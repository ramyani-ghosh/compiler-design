%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 10
int curr_scope = 0;
int insideloop = 0;
int opening_brackets = 0;
int closing_brackets = 0;
int nesting = 0;

typedef struct Node{
	struct Node *left;
	struct Node *right;
	char token[100];
	struct Node *val;
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
	char value[30][30]; 	//saving value as a string
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
	char value[30][30];
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
typedef struct Trunk
{
	struct Trunk *prev;
	char str[100];
}Trunk;


void push_scope(int);
void pop_scope();
int peep_scope();
void create_node(char *token, int leaf);
void push_tree(Node *newnode);
Node* pop_tree();
Node* pop_tree_2();
void modify_top(char *s);
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
void printTree(Node* root, Trunk*,int);
void showTrunks(Trunk *p);
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
%type <string> primary_expression postfix_expression unary_expression multiplicative_expression additive_expression relational_expression equality_expression expression initializer_list

%start hashinclude
%%

primary_expression
	: IDENTIFIER	{ strcpy($$, $1); create_node($1, 1);exists($1);}
    | CHAR_CONSTANT		{ strcpy($$, $1); create_node($1, 1);}
	| FLOAT_CONSTANT	{ strcpy($$, $1); create_node($1, 1);}
    | CONSTANT          { strcpy($$, $1); create_node($1, 1);}
    | INT_CONSTANT		{ strcpy($$, $1); create_node($1, 1);}
	| STRING_LITERAL	{ strcpy($$, $1); create_node($1, 1);}
	| '(' expression ')'	{}
	;

postfix_expression
	: primary_expression	{ strcpy($$, $1); }
	| postfix_expression '[' expression ']'	{
												pop_tree();
												pop_tree();
												char s[30];
												strcpy(s, $1);
												strcat(s, "[");
												strcat(s, $3);
												strcat(s, "]");
												create_node(s, 1);
												strcpy($$, s);

											}
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

		create_node("1",1);
		create_node("+", 0);

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

		create_node("1",1);
		create_node("-", 0);

	}
	;

argument_expression_list
	: assignment_expression		{}
	| argument_expression_list ',' assignment_expression	{}
	;

unary_expression
	: postfix_expression	{ strcpy($$, $1); }
	| INC_OP unary_expression	{

		int d1 = $2[0] - '0';
		if(d1>=0 && d1 <= 9)
		{
			printf("\n%*s\n%*s   <--- invalid operation \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		else
		{
			int s = atoi(get_val($2, curr_scope)) + 1;
			char str[10];
			// printf("%d", s);
			snprintf(str, 10, "%d", s);
			addval($2, str, curr_scope);
		}

		create_node("1",1);
		create_node("+", 0);

	}
	| DEC_OP unary_expression	{

		int d1 = $2[0] - '0';
		if(d1>=0 && d1 <= 9)
		{
			printf("\n%*s\n%*s   <--- invalid operation \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		else
		{
			int s = atoi(get_val($2, curr_scope)) - 1;
			char str[10];
			// printf("%d", s);
			snprintf(str, 10, "%d", s);
			addval($2, str, curr_scope);
		}
		create_node("1",1);
		create_node("-", 0);

	}
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
	| relational_expression '<' additive_expression		{

															create_node("<", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) < atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) < atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) < atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) < atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
														}
	| relational_expression '>' additive_expression		{
															create_node(">", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) > atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) > atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) > atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) > atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
														}
	| relational_expression LE_OP additive_expression	{
															create_node("<=", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) <= atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) <= atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) <= atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) <= atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
														}
	| relational_expression GE_OP additive_expression	{
															create_node(">=", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) >= atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) >= atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) >= atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) >= atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
														}
	;

equality_expression
	: relational_expression	{ strcpy($$, $1); }
	| equality_expression EQ_OP relational_expression	{
															create_node("==", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) == atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) == atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) == atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) == atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
														}
	| equality_expression NE_OP relational_expression	{
															create_node("!=", 0);
															int d1 = $1[0] - '0';
															int d2 = $3[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi($1) != atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi($1) != atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val($1, curr_scope)) != atoi($3);
																snprintf($$, 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val($1, curr_scope)) != atoi(get_val($3, curr_scope));
																snprintf($$, 10, "%d", s);
															}
														}
	;

logical_and_expression
	: equality_expression	{ strcpy($$, $1); }
	| logical_and_expression AND_OP equality_expression		{
																create_node("&&", 0);
																int d1 = $1[0] - '0';
																int d2 = $3[0] - '0';
																if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
																{
																	int s = atoi($1) && atoi($3);
																	snprintf($$, 10, "%d", s);
																}
																else if(d1>=0 && d1<=9)
																{
																	int s = atoi($1) && atoi(get_val($3, curr_scope));
																	snprintf($$, 10, "%d", s);
																}
																else if(d2>=0 && d2<=9)
																{
																	int s = atoi(get_val($1, curr_scope)) && atoi($3);
																	snprintf($$, 10, "%d", s);
																}
																else
																{
																	int s = atoi(get_val($1, curr_scope)) && atoi(get_val($3, curr_scope));
																	snprintf($$, 10, "%d", s);
																}
															}
	;

logical_or_expression
	: logical_and_expression	{ strcpy($$, $1); }
	| logical_or_expression OR_OP logical_and_expression	{
																create_node("||", 0);
																int d1 = $1[0] - '0';
																int d2 = $3[0] - '0';
																if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
																{
																	int s = atoi($1) || atoi($3);
																	snprintf($$, 10, "%d", s);
																}
																else if(d1>=0 && d1<=9)
																{
																	int s = atoi($1) || atoi(get_val($3, curr_scope));
																	snprintf($$, 10, "%d", s);
																}
																else if(d2>=0 && d2<=9)
																{
																	int s = atoi(get_val($1, curr_scope)) || atoi($3);
																	snprintf($$, 10, "%d", s);
																}
																else
																{
																	int s = atoi(get_val($1, curr_scope)) || atoi(get_val($3, curr_scope));
																	snprintf($$, 10, "%d", s);
																}
															}
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
	| '{' initializer_list '}'	{
									char s[20] = "{";
									strcat(s, $2);
									strcat(s, "}");
									strcpy($$, s);
									for(int i=0; s[i]!='}'; i++)
									{
										Node *n;
										if(s[i]==',')
											n=pop_tree();
									}
									pop_tree();
									create_node(s, 1);
								}
	| '{' initializer_list ',' '}'	{
										char s[20] = "{";
										strcat(s, $2);
										strcat(s, ",}");
										strcpy($$, s);
										create_node(s, 1);
									}
	;

initializer_list
	: initializer	{ strcpy($$, $1);}
	| initializer_list ',' initializer	{
											char s[100] = "";
											strcat(s, $1);
										 	strcat(s, ", ");
											strcat(s, $3);
											strcpy($$, s);
										}
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
										if((0<= $3[0]-'0' && 9>=$3[0]-'0') || $3[0]=='\'' || $3[0]== '"')
										{
											tempval($1, val, 0, 1);
											strcpy($$,$1);
										}
										else if($3[0]=='{')
										{
											tempval($1, $3, 1, 0);
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
	: IDENTIFIER            { create_node($1, 1); strcpy($$,$1);}
	/* | '(' declarator ')' */
	| declarator '[' INT_CONSTANT ']' {
										Node * n= pop_tree();
										char s[30] = "";
										strcat(s, $1);
										strcat(s,"[");
										strcat(s, $3);
										strcat(s, "]");
										create_node(s, 1);
										tempval($1, "{0}", 1, atoi($3)); strcpy($$, $1); }
	| declarator '(' parameter_list ')'	{}
	| declarator '(' identifier_list ')'	{}
	| declarator '(' ')'	{strcpy($$, $1); }
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
	: WHILE '(' expression ')' {insideloop = 1; } compound_statement { insideloop = 0; create_node("while", 0);}
	| DO  {insideloop = 1; }  compound_statement WHILE '(' expression ')' ';' {insideloop = 0; create_node("do-while", 0);}
	;


jump_statement
	: CONTINUE ';'	{}
	| BREAK ';'		{
						if(!insideloop)
						{
							printf("\n%*s\n%*s   <--- break statement not within loop \n", column, "^", column, wrong_symbol);
							exit(0);
						}
					}
	| RETURN ';'	{ create_node("return",1);}
	| RETURN expression ';'	{ char s[20] = "return ";
							  strcat(s, $2);
							  modify_top(s);}
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
	: type_specifier declarator compound_statement	{}	{ lookup($2, $1, "function"); }
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
void modify_top(char *s)
{
	strcpy(tree_top->node->token, s);
}

Node* pop_tree()
{
	if(tree_top==NULL)
		return NULL;
	tree_stack *temp = tree_top;
	tree_top = tree_top->next;
	Node *retnode = temp->node;
	free(temp);
	return retnode;
}
Node* pop_tree_2()
{
	if(tree_top==NULL)
		return NULL;
	tree_stack *temp = tree_top->next;
	tree_top->next = tree_top->next->next;
	Node *retnode = temp->node;
	free(temp);
	return retnode;
}
// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
	if (p == NULL)
		return;

	showTrunks(p->prev);

	printf("%s",p->str);
}

// Recursive function to print binary tree
// It uses inorder traversal
void printTree(Node *root, Trunk *prev, int isLeft)
{
	if (root == NULL)
		return;

	char prev_str[100] = "	  ";
	Trunk *trunk = (Trunk*)malloc(sizeof(Trunk));
	trunk->prev = prev;
	strcpy(trunk->str, prev_str);

	printTree(root->right, trunk, 1);

	if (!prev) //if prev == NULL
		strcpy(trunk->str,"---");
	else if (isLeft)
	{
		strcpy(trunk->str,".---");
		strcpy(prev_str,"\t  |");
	}
	else
	{
		strcpy(trunk->str,"`---");
		strcpy(prev->str,prev_str);
	}

	showTrunks(trunk);
	printf(" %s\n",root->token);
	if (prev)
		strcpy(prev->str,prev_str);
	strcpy(trunk->str,"\t  |");

	printTree(root->left, trunk, 0);
}

void printtree(Node *tree)
{
	int i;
	if (tree->left || tree->right)
 		printf("(");
	printf(" %s ", tree->token);
	if (tree->left)
		printtree(tree->left);
	if (tree->right)
		printtree(tree->right);
	if (tree->left || tree->right)
		printf(")");
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


symbol_table* initialize()
{
	symbol_table *temp = (symbol_table*)malloc(sizeof(symbol_table));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->type = (char*)malloc(sizeof(char)*10);
	temp->symbol = (char*)malloc(sizeof(char)*11);
	strcpy(temp->value[0], "0");
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
	if((0<= val[0]-'0' && 9>=val[0]-'0') || val[0]=='\'')
	{
		int k;
	}
	else
	{
		strcpy(val,get_val(val, curr_scope));
	}
	while(temp!=NULL)
	{
		if(strcmp(temp->name, var)==0)
		{
			if(temp->scope == scope && temp->isarray!=1)
			{
				strcpy(temp->value[0], val);
			}
			else if(temp->isarray)
			{
				// if(val[0]!=)
				printf("\n%*s\n%*s   <--- Assignment to expression with array type \n", column, "^", column, wrong_symbol);
				exit(0);
			}
		}
		else if(temp->name[0]==var[0])
		{
			int i=0;
			int flag = 0;
			for(i=0; temp->name[i]!= '\0';i++)
			{
				if(var[i]!=temp->name[i])
				{
					flag = 1;
					break;
				}
			}
			//val is the value to be stored
			//temp->name and var is the name of the variable
			if(flag)
				break;
			i = i+1;
			char size[10]="";
			int pos = i;
			while(var[i]!=']')
			{
				size[i-pos] = var[i];
				i++;
			}
			int index = atoi(size);
			strcpy(temp->value[index], val);
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
		// printf("%s ", temp->name, var);
		if(strcmp(temp->name, var)==0)
		{
			if(temp->scope <= scope)
			{
				return temp->value[0];
			}
		}
		else if(temp->name[0]==var[0])
		{
			int i=0;
			int flag = 0;
			for(i=0; temp->name[i]!= '\0';i++)
			{
				if(var[i]!=temp->name[i])
				{
					flag = 1;
					break;
				}
			}
			if(flag)
			{
				temp=temp->next;
				continue;
			}
			i = i+1;
			char size[10]="";
			int pos = i;
			while(var[i]!=']')
			{
				size[i-pos] = var[i];
				i++;
			}
			int index = atoi(size);
			return temp->value[index];
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
			for(int i=0; i<temp->size; i++)
			{
				strcpy(new_entry->value[i], temp->value[i]);
				// printf("%s", temp->value[i]);
			}

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
	temp->next = NULL;
	strcpy(temp->name, var);
	strcpy(temp->value[0], val);
	temp->isarray = isarray;
	temp->size = size;
	tempvals *t =tvhead;
	while(t!=NULL)
	{
		if(strcmp(t->name, temp->name)==0)
		{

			if(isarray)
			{
				int pos = 0;
				int i=1;
				int index = 0;
				while(val[i]!='}')
				{
					char num[30]="";
					pos = i;
					while(val[i]!=',' &&val[i]!='}' &&val[i]!=' ')
					{
						num[i-pos] = val[i];
						i++;
					}
					if(strcmp(num, "")!=0)
						strcpy(t->value[index++], num);
					if(val[i]=='}')
						break;
					i++;
				}
				return;
			}
		}
		t=t->next;
	}

	if(tvhead == NULL)
	{
		tvhead = temp;
	}
	else
	{
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
	free(temp);
}
void display()
{
	symbol_table *temp = st;
	printf("\n ͟S͟y͟m͟b͟o͟l͟ ͟T͟a͟b͟l͟e͟ \n\n");
	printf("Symbol \t\t     Name \t\t Array \t\t Type \t\t Scope \t Size \t Line Number \t Lines Used \t Value \n");
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	while(temp!=NULL)
	{
		if(strcmp(temp->name, "keyword")==0)
		{
			printf("%s \t %8s \t\t %d \t\t %s \t\t %d \t %d \t %d \t\t [ ",temp->symbol, temp->name, temp->isarray, temp->type, temp->scope, temp->var_size, temp->lno);
			for(int i=0; i<temp->size; i++)
			{
				if((temp->lno_used[i])!=0)
					printf("%d ", temp->lno_used[i]);
			}
			printf("]\t\t");
			for(int i=0; i<30; i++)
			{
				printf("%s ", temp->value[i]);
			}
			printf("\n");
		}
		else
		{
			printf("%s \t %8s \t\t %d \t\t %s \t\t %d \t %d \t %d \t\t [ ",temp->symbol, temp->name, temp->isarray, temp->type, temp->scope, temp->var_size, temp->lno);
			for(int i=0; i<temp->size; i++)
			{
				if((temp->lno_used[i])!=0)
					printf("%d ", temp->lno_used[i]);
			}
			printf("]\t\t");
			for(int i=0; i<30; i++)
			{
				printf("%s ", temp->value[i]);
			}
			printf("\n");
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

	//Display symbol table
	display(st);
	//Display AST
	printtree(root);
	printf("\n");
	printTree(root, NULL, 0);
	//Display IC
	printICG(q);
	fclose(yyin);

}
