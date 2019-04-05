%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 10
int curr_scope = 0;
int opening_brackets = 0;
int closing_brackets = 0;
int nesting = 0;

typedef struct Node{
	struct Node *left;
	struct Node *right;
	char token[100];
	struct Node *val;
	int level;
}Node;

typedef struct tree_stack{
	Node *node;
	struct tree_stack *next;
}tree_stack;

typedef struct symbol_table
{
	char *name;		//name of the token	(in case of keywords, the name is the "keyword" itself)
	char *symbol;
	char *type;		//type of token (in case of keywords, the type is the name of the keyword)
	char *value; 	//saving value as a string
	int lno;		//line number where token is declared (default 0)
	int *lno_used;	//line number where token is first used (defult 0)
	int size;		//size of the token
	int var_size;
	int scope;
	int isarray;
	struct symbol_table *next;	//symbol table is LL
}symbol_table;

typedef struct tempvals
{
	char *name;
	char *value;
	int isarray;
	int size;
	struct tempvals *next;
}tempvals;

typedef struct scope_stack
{
	int scope;
	struct scope_stack *next;
}scope_stack;

typedef struct quad
{
		char op;
		char arg1;
		char arg2;
		char res;
}quad;


void get_levels(Node *root, int level);
void push_scope(int);
void pop_scope();
int peep_scope();
void create_node(char *token, int leaf);
void push_tree(Node *newnode);
Node* pop_tree();
int lookup(char *s, char *type, char*);
symbol_table* initialize();
void insert(char *s, char *type, char*);
void deletetempval(tempvals *temp);
void tempval(char *var, char *val, int, int);
void check_scope(char *s, char *type, char *token_type);
void addval(char *var, char *val, int scope);
char * get_val(char *var, int scope);
void add_lines_used(char *s);
void exists(char *s);
void set_arr();
void unset_arr();
void printtree(Node *tree);
int getmaxlevel(Node *root);
void printGivenLevel(Node* root, int level, int h);
void printICG(quad *q);

extern char yytext[];
extern int line_number;
extern int column;
extern FILE *yyin;

//Global variables
tree_stack *tree_top = NULL;
scope_stack *scope_top = NULL;
tempvals *tvhead =NULL;
symbol_table *st = NULL;
int scope_error= 0;
char *wrong_symbol;


%}

%union
{
	int ival;
	char string[128];
}

%token IDENTIFIER CONSTANT CHAR_CONSTANT INT_CONSTANT FLOAT_CONSTANT STRING_LITERAL SIZEOF
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP H
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
%token CHAR SHORT INT LONG FLOAT DOUBLE VOID

%token IF ELSE WHILE DO CONTINUE BREAK RETURN
%token HASH INCLUDE LIBRARY

%type <string> IDENTIFIER CONSTANT CHAR_CONSTANT FLOAT_CONSTANT INT_CONSTANT STRING_LITERAL SIZEOF INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP H AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN CHAR SHORT INT LONG FLOAT DOUBLE VOID
%type <string>  IF ELSE  CONTINUE BREAK RETURN HASH INCLUDE LIBRARY
%type <string> declaration init_declarator_list init_declarator type_specifier declarator logical_and_expression logical_or_expression conditional_expression assignment_expression initializer
%type <string> primary_expression postfix_expression unary_expression multiplicative_expression additive_expression relational_expression equality_expression expression

%start hashinclude
%%

primary_expression
	: IDENTIFIER	{ strcpy($$, $1); exists($1); create_node($1, 1);}
    | CHAR_CONSTANT		{ strcpy($$, $1); create_node($1, 1);}
	| FLOAT_CONSTANT	{ strcpy($$, $1); create_node($1, 1);}
    | CONSTANT          { strcpy($$, $1); create_node($1, 1);}
    | INT_CONSTANT		{ strcpy($$, $1); create_node($1, 1);}
	| STRING_LITERAL	{}
	| '(' expression ')'	{}
	;

postfix_expression
	: primary_expression	{ strcpy($$, $1); }
	| postfix_expression '[' expression ']'	{}
	| postfix_expression '(' ')'	{}
	| postfix_expression '(' argument_expression_list ')'	{}
	| postfix_expression '.' IDENTIFIER		{ exists($3);}
	| postfix_expression INC_OP		{

		int d1 = $1[0] - '0';
		if(d1>=0 && d1 <= 9)
		{
			printf("\n%*s\n%*s   <--- invalid operation \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		else
		{
			int s = atoi(get_val($1, curr_scope)) + 1;
			char str[10];
			// printf("%d", s);
			snprintf(str, 10, "%d", s);
			addval($1, str, curr_scope);
		}

	}
	| postfix_expression DEC_OP		{

		int d1 = $1[0] - '0';
		if(d1>=0 && d1 <= 9)
		{
			printf("\n%*s\n%*s   <--- invalid operation \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		else
		{
			int s = atoi(get_val($1, curr_scope)) - 1;
			char str[10];
			// printf("%d", s);
			snprintf(str, 10, "%d", s);
			addval($1, str, curr_scope);
		}

	}
	;

argument_expression_list
	: assignment_expression		{}
	| argument_expression_list ',' assignment_expression	{}
	;

unary_expression
	: postfix_expression	{ strcpy($$, $1); }
	| INC_OP unary_expression	{}
	| DEC_OP unary_expression	{}
	| unary_operator unary_expression	{}
	| SIZEOF unary_expression	{}
	| SIZEOF '(' type_specifier ')'	{}
	;

unary_operator
	: '&'	{}
	| '*'	{}
	| '+'	{}
	| '-'	{}
	| '~'	{}
	| '!'	{}
	;

multiplicative_expression
	: unary_expression	{ strcpy($$, $1); }
	| multiplicative_expression '*' unary_expression	{
															create_node("*", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) * atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) * atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) * atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) * atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}

														}
	| multiplicative_expression '/' unary_expression	{
															create_node("/", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) / atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) / atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) / atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) / atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}

														}
	| multiplicative_expression '%' unary_expression	{
															create_node("%", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) % atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) % atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) % atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) % atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}

														}
	;

additive_expression
	: multiplicative_expression	{ strcpy($$, $1); }
	| additive_expression '+' multiplicative_expression		{
															create_node("+", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) + atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) + atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) + atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) + atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}

														}
	| additive_expression '-' multiplicative_expression		{
															create_node("-", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) - atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) - atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) - atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) - atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}

														}
	;

relational_expression
	: additive_expression	{ strcpy($$, $1); }
	| relational_expression '<' additive_expression		{create_node("<", 0);}
	| relational_expression '>' additive_expression		{create_node(">", 0);}
	| relational_expression LE_OP additive_expression	{create_node("<=", 0);}
	| relational_expression GE_OP additive_expression	{create_node(">=", 0);}
	;

equality_expression
	: relational_expression	{ strcpy($$, $1); }
	| equality_expression EQ_OP relational_expression	{create_node("==", 0);}
	| equality_expression NE_OP relational_expression	{create_node("!=", 0);}
	;

logical_and_expression
	: equality_expression	{ strcpy($$, $1); }
	| logical_and_expression AND_OP equality_expression		{create_node("&&", 0);}
	;

logical_or_expression
	: logical_and_expression	{ strcpy($$, $1); }
	| logical_or_expression OR_OP logical_and_expression	{create_node("||", 0);}
	;

conditional_expression
	: logical_or_expression	{ strcpy($$, $1); }
	| logical_or_expression '?' expression ':' conditional_expression	{}
	;

assignment_expression
	: conditional_expression	{ strcpy($$, $1); }
	| unary_expression assignment_operator assignment_expression	{
																		addval($1, $3, curr_scope);
																		create_node("=", 0);
																	}
	;

assignment_operator
	: '='	{}
	| MUL_ASSIGN	{}
	| DIV_ASSIGN	{}
	| MOD_ASSIGN	{}
	| ADD_ASSIGN	{}
	| SUB_ASSIGN	{}

	;

expression
	: assignment_expression	{ strcpy($$, $1); }
	| expression ',' assignment_expression	{}
	;




parameter_list
	: parameter_declaration	{}
	| parameter_list ',' parameter_declaration	{}
	;

parameter_declaration
	: type_specifier declarator		{}//{	lookup($1, $2);		}
	| type_specifier	{}
	;

identifier_list
	: IDENTIFIER	{
		exists($1);
	}
	| identifier_list ',' IDENTIFIER	{	exists($3); }
	;


initializer
	: assignment_expression	{ strcpy($$, $1); }
	| '{' initializer_list '}'	{}
	| '{' initializer_list ',' '}'	{}
	;

initializer_list
	: initializer	{}
	| initializer_list ',' initializer	{}
	;

statement //HERE YOU MADE CHANGE
	: compound_statement
	| expression_statement	{}
	| selection_statement	{}
	| iteration_statement {}
	| jump_statement		{}
    | declaration     {}
	;


compound_statement
	: {opening_brackets++; curr_scope = opening_brackets; push_scope(curr_scope);} compound_statement_types { pop_scope(); curr_scope =  peep_scope(); }
	;

compound_statement_types
	: '{' '}'
	| '{' statement_list '}'
	;

declaration
	: type_specifier init_declarator_list ';'	{
								// printf("%s %s", $1, $2);
								char *p = strtok($2, ",");
								while(p!=NULL)
								{
									lookup(p, $1, "identifier");
									p=strtok(NULL, ",");
								}

							}
	;

init_declarator_list
	: init_declarator		{strcpy($$,$1);}
	| init_declarator_list ',' init_declarator		{
														strcpy($$,$3);
														strcat($$, ",");
														strcat($$, $1);
													}
	;

init_declarator
	: declarator 	{strcpy($$,$1);}
	| declarator '=' initializer	{
										create_node("=", 0);
										char val[20];
										strcpy(val, $3);
										printf("%s", val);
										if((0<= $3[0]-'0' && 9>=$3[0]-'0') || $3[0]=='\'')
										{
											tempval($1, val, 0, 1);
											strcpy($$,$1);
										}
										else
										{
											strcpy(val,get_val($3, curr_scope));
											tempval($1, val, 0, 1);
											strcpy($$,$1);
										}
									}
	;

type_specifier
	: VOID		{strcpy($$,$1);}
	| CHAR		{}
	| SHORT		{}
	| INT		{strcpy($$,$1);}
	| LONG		{}
	| FLOAT		{}
	| DOUBLE	{}
	;

declarator
	: IDENTIFIER            {create_node($1, 1); strcpy($$,$1);}
	/* | '(' declarator ')' */
	| declarator '[' INT_CONSTANT ']' { tempval($1, "{0}", 1, atoi($3)); strcpy($$, $1); }
	| declarator '(' parameter_list ')'	{}
	| declarator '(' identifier_list ')'	{}
	| declarator '(' ')'	{strcpy($$, $1);}
	;

statement_list
	: statement	{}
	| statement_list statement	{ create_node("stmt", 0);}
	;

expression_statement
	: ';'	{}
	| expression ';'	{}
	;

selection_statement
	: IF '(' expression ')' compound_statement { create_node("if", 0);}
	| IF '(' expression ')' compound_statement ELSE compound_statement{create_node("else", 0); create_node("if", 0);}
	;

iteration_statement
	: WHILE '(' expression ')' compound_statement {create_node("while", 0);}
	| DO compound_statement WHILE '(' expression ')' ';' {}
	;


jump_statement
	: CONTINUE ';'	{}
	| BREAK ';'	{}
	| RETURN ';'	{ create_node("return", 1);}
	| RETURN expression ';'	{}
	;

hashinclude
	: HASH INCLUDE '<' IDENTIFIER '.' H '>' hashinclude	{}
	| translation_unit {} //{display(st);}
	;

translation_unit
	: external_declaration	{}
	| translation_unit external_declaration	{}
	;

external_declaration
	: function_definition	{}
	| declaration	{}
	;

function_definition
	: type_specifier declarator compound_statement	{}	{ lookup($2, $1, "function"); create_node($2, 3);}
	| declarator declaration compound_statement {}
	| declarator compound_statement	{}
	;

%%

int scopeinstack(int scope)
{
	scope_stack *temp = scope_top;
	while(temp!=NULL)
	{
		if(temp->scope == scope)
			return 1;
		temp = temp->next;
	}
	return 0;
}
void push_scope(int scope)
{
	scope_stack *temp= (scope_stack*)malloc(sizeof(scope_stack));
	temp->scope = scope;
	temp->next = scope_top;
	scope_top = temp;
}

void pop_scope()
{
	scope_stack *temp = scope_top;
	scope_top = scope_top->next;
	free(temp);
}

int peep_scope()
{
	return scope_top->scope;
}

void create_node(char *token, int leaf)
{
	Node *l;
	Node *r;
	if(leaf==0)
	{
		r = pop_tree();
		l = pop_tree();
	}
	else if(leaf ==1)
	{
		l = NULL;
		r = NULL;
	}
	else
	{
		l = pop_tree();
		r = NULL;
	}
	Node *newnode = (Node*)malloc(sizeof(Node));
	strcpy(newnode->token, token);
	newnode->left = l;
	newnode->right = r;
	push_tree(newnode);
}
void push_tree(Node *newnode)
{
	tree_stack *temp= (tree_stack*)malloc(sizeof(tree_stack));
	temp->node = newnode;
	temp->next = tree_top;
	tree_top = temp;
}

Node* pop_tree()
{
	tree_stack *temp = tree_top;
	tree_top = tree_top->next;
	Node *retnode = temp->node;
	free(temp);
	return retnode;
}
// void printtree(Node *tree, int x)
// {
// 	int i;
// 	if (tree->left || tree->right)
//  		printf("(");
// 	printf(" %s ", tree->token);
// 	if (tree->left)
// 		printtree(tree->left, 0);
// 	if (tree->right)
// 		printtree(tree->right, 0);
// 	if (tree->left || tree->right)
// 		printf(")");
// }
void get_levels(Node *root, int level)
{
	root->level = level;
	if(root->left == NULL && root->right == NULL)
	{
		return;
	}
	if(root->left == NULL)
	{
		get_levels(root->right, level+1);
	}
	else if(root->right == NULL)
	{
		get_levels(root->left, level+1);
	}
	else
	{
		get_levels(root->left, level+1);
		get_levels(root->right, level+1);
	}
}

int getmaxlevel(Node *root)
{
	int count=0;
	Node *temp= root;
	while(temp->left!=NULL)
	{
		count++;
		temp=temp->left;
	}
	return count*2;
}
void printtree(Node* root)
{
    int h = getmaxlevel(root)-1;
    int i;

		printf("\n\n ͟A͟b͟s͟t͟r͟a͟c͟t͟ ͟S͟y͟n͟t͟a͟x͟ ͟T͟r͟e͟e͟ \n\n");
    for (i=1; i<=h; i++)
    {
			  printf("\t");
				for(int j=0;j<=h+1-i;j++)
				{
					printf("     ");
				}
        printGivenLevel(root, i,h);
        printf("\n\n\n");

    }
}

void printICG(quad *q)
{
	printf("\n\n ͟I͟n͟t͟e͟r͟m͟e͟d͟i͟a͟t͟e͟ ͟C͟o͟d͟e͟\n\n");
	printf("\t  op");
	printf("\t    arg1");
	printf("\t    arg2");
	printf("\t    result");
	printf("\n\t ____________________________________________________\n\n");
}


void printGivenLevel(Node* root, int level, int h)
{
    if (root == NULL)
        return;
    if (level == 1)
		{
			for(int j=0;j<=h-1-level;j++)
			{
					printf(" ");
			}
	        printf("%s ", root->token);
		}
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1,h);
				for(int j=0;j<=h-1-level;j++)
				{
						printf(" ");
				}
        printGivenLevel(root->right, level-1,h);
    }
}

symbol_table* initialize()
{
	symbol_table *temp = (symbol_table*)malloc(sizeof(symbol_table));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->type = (char*)malloc(sizeof(char)*10);
	temp->symbol = (char*)malloc(sizeof(char)*11);
	temp->value = (char*)malloc(sizeof(char)*10);
	strcpy(temp->value, "0");
	temp->lno = 0;
	temp->lno_used = (int*)malloc(sizeof(int)*100);
	temp->size = 0;
	temp->var_size = 0;
	temp->next = NULL;
	temp->scope = curr_scope;
	temp->isarray = 0;
	return temp;
}


void addval(char *var, char *val, int scope)
{
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		if(strcmp(temp->name, var)==0)
		{
			if(temp->scope == scope)
			{
				strcpy(temp->value, val);
			}
		}
		temp=temp->next;
	}
	add_lines_used(var);
}

char * get_val(char *var, int scope)
{
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		if(strcmp(temp->name, var)==0)
		{
			if(temp->scope == scope)
			{
				return temp->value;
			}
		}
		temp=temp->next;
	}
	return "0";
}

void add_lines_used(char *s)
{
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		if(strcmp(temp->name, s)==0)
		{
			if(temp->scope == curr_scope)
			{
				temp->size +=1;
				temp->lno_used[temp->size-1] = line_number;
			}
		}
		temp=temp->next;
	}
}

void exists(char *s)
{
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		if(strcmp(temp->name, s)==0)
		{
			// if(temp->scope <= curr_scope)
			if(scopeinstack(temp->scope))
			{
				return;
			}
		}
		temp=temp->next;
	}
	printf("\n%*s\n%*s   <--- undeclared variable \n", column, "^", column, wrong_symbol);
	exit(0);
}

int lookup(char *s, char *type, char *token_type)
{
	check_scope(s,type,token_type);
	if(st == NULL)
	{

		insert(s, type, token_type);
		return 0;
	}
	symbol_table *temp = st;
	while(st!=NULL)
	{
		if(strcmp(st->name, s)==0 && st->scope == curr_scope) //strcmp(st->type,type)==0
		{
	  		check_scope(s,type,token_type);
			return 0;
		}
		st = st->next;
	}
	st = temp;
//  check_scope(s,type,token_type);
	insert(s, type, token_type);

	return 0;
}

void check_scope(char *s, char *type, char *token_type)
{

  wrong_symbol=(char*)malloc(128*sizeof(char));
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		if(strcmp(temp->name, s)==0&&temp->scope==curr_scope)
		{
			strcpy(wrong_symbol, temp->name);
			scope_error=1;
			printf("\n%*s\n%*s   <--- already declared in current scope \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		temp = temp->next;
	}

}

void insert(char *s, char *type, char* token_type)
{
	symbol_table *new_entry;
	if(st==NULL)
	{
		st = initialize();
		new_entry = st;

	}
	else
	{
		symbol_table *temp = st;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		new_entry = initialize();
		temp->next = new_entry;
	}
	strcpy(new_entry->name, s);
	tempvals *temp = tvhead;
	int isarray = 0;
	int arrsize = 0;
	while(temp!=NULL)
	{
		if(strcmp(new_entry->name, temp->name)==0)
		{
			strcpy(new_entry->value, temp->value);
			new_entry->isarray = temp ->isarray;
			arrsize = temp->size;
			deletetempval(temp);
		}
		temp = temp->next;
	}
	strcpy(new_entry->type, type);
	strcpy(new_entry->symbol, token_type);
	new_entry->lno = line_number;
	new_entry->size = 1;
	new_entry->lno_used[0] = line_number;
	if(strcmp(type, "int")==0)
		new_entry->var_size = 4;
	else if(strcmp(type, "char")==0)
		new_entry->var_size = 1;
	else if(strcmp(type, "float")==0)
		new_entry->var_size = 4;
	if(new_entry->isarray == 1)
	{
		new_entry->var_size *= arrsize;
	}

}


void tempval(char *var, char *val, int isarray, int size)
{

	tempvals *temp = (tempvals*)malloc(sizeof(tempvals));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->value = (char*)malloc(sizeof(char)*10);
	temp->next = NULL;
	strcpy(temp->name, var);
	strcpy(temp->value, val);
	temp->isarray = isarray;
	temp->size = size;
	if(tvhead == NULL)
	{
		tvhead = temp;
	}
	else{
		tempvals *t = tvhead;
		while(t->next!=NULL)
		{
			t =t->next;
		}
		t->next = temp;
	}

}

void deletetempval(tempvals *temp)
{
	if(temp == tvhead)
	{
		tempvals *t = temp;
		tvhead = temp->next;
	}
	else
	{
		tempvals *t = tvhead;
		while(t->next != temp)
			t=t->next;
		t->next = t->next->next;
	}

	free(temp->name);
	free(temp->value);
	free(temp);
}
void display()
{
	symbol_table *temp = st;
	printf("\n ͟S͟y͟m͟b͟o͟l͟ ͟T͟a͟b͟l͟e͟ \n\n");
	printf("Symbol \t\t     Name \t\t Array \t\t Type \t\t Scope \t Value \t Size \t Line Number \t Lines Used\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	while(temp!=NULL)
	{
		if(strcmp(temp->name, "keyword")==0)
		{
			printf("%s \t %8s \t\t %d \t\t %s \t\t %d \t %s \t %d \t %d \t\t\t [ ",temp->symbol, temp->name, temp->isarray, temp->type, temp->scope, temp->value, temp->var_size, temp->lno);
			for(int i=0; i<temp->size; i++)
			{
				if((temp->lno_used[i])!=0)
					printf("%d ", temp->lno_used[i]);
			}

			printf("]\n");
		}
		else
		{
			printf("%s \t %8s \t\t %d \t\t %s \t\t %d \t %s \t %d \t %d \t\t\t [ ",temp->symbol, temp->name, temp->isarray, temp->type, temp->scope, temp->value, temp->var_size, temp->lno);
			for(int i=0; i<temp->size; i++)
			{
				if((temp->lno_used[i])!=0)
					printf("%d ", temp->lno_used[i]);
			}

			printf("]\n");
		}

		temp = temp->next;
	}
}


yyerror(s)
char *s;
{
	fflush(stdout);

		printf("\n%*s\n%*s\n", column, "^", column, s);


}

int main()
{
	yyin = fopen("program.c", "r");
	lookup("char", "NIL", "keyword");
	lookup("int", "NIL", "keyword");
	lookup("float", "NIL", "keyword");
	lookup("short", "NIL", "keyword");
	lookup("long", "NIL", "keyword");
	lookup("double", "NIL", "keyword");
	lookup("void", "NIL", "keyword");
	lookup("if", "NIL", "keyword");
	lookup("else", "NIL", "keyword");
	lookup("while", "NIL", "keyword");
	lookup("do", "NIL", "keyword");
	lookup("continue", "NIL", "keyword");
	lookup("break", "NIL", "keyword");
	lookup("return", "NIL", "keyword");
	lookup("printf", "NIL", "function");

	scope_top = (scope_stack*)malloc(sizeof(scope_stack));
	scope_top->scope = 0;
	scope_top->next=NULL;
	tree_top = (tree_stack*)malloc(sizeof(tree_stack));
	tree_top->node = NULL;
	tree_top->next = NULL;
	struct Node *root;
	yyparse();
	root = pop_tree();
	quad *q;

	//Assign levels to nodes
	get_levels(root, 1);
	//Display symbol table
	display(st);
	//Display AST
	printtree(root);
	//Display IC
	printICG(q);
	fclose(yyin);

}
