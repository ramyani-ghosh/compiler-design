%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr_scope = 0;
typedef struct symbol_table
{
	char *name;		//name of the token	(in case of keywords, the name is the "keyword" itself)
	char *symbol;
	char *type;		//type of token (in case of keywords, the type is the name of the keyword)
	char *value; 	//saving value as a string
	int lno;		//line number where token is declared (default 0)
	int *lno_used;	//line number where token is first used (defult 0)
	int size;		//size of the token
	int scope;
	struct symbol_table *next;	//symbol table is LL
}symbol_table;

typedef struct tempvals
{
	char *name;
	char *value;
	struct tempvals *next;
}tempvals;

tempvals *tvhead =NULL;
symbol_table *st = NULL;
int lookup(char *s, char *type, char*);
symbol_table* initialize();
void insert(char *s, char *type, char*);
void deletetempval(tempvals *temp);
void tempval(char *var, char *val);


extern char yytext[];
extern int column;
extern FILE *yyin;


%}

%union
{
	int ival;
	char string[128];
}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP H
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
%token CHAR SHORT INT LONG FLOAT DOUBLE VOID

%token IF ELSE  CONTINUE BREAK RETURN
%token HASH INCLUDE LIBRARY

%type <string> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP H AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN CHAR SHORT INT LONG FLOAT DOUBLE VOID
%type <string>  IF ELSE  CONTINUE BREAK RETURN HASH INCLUDE LIBRARY
%type <string> declaration init_declarator_list init_declarator type_specifier declarator logical_and_expression logical_or_expression conditional_expression assignment_expression initializer
%type <string> primary_expression postfix_expression unary_expression multiplicative_expression additive_expression relational_expression equality_expression expression

%start hashinclude
%%

primary_expression
	: IDENTIFIER	{}
	| CONSTANT		{ strcpy($$, $1);}
	| STRING_LITERAL	{}
	| '(' expression ')'	{}
	;

postfix_expression
	: primary_expression	{ strcpy($$, $1); }
	| postfix_expression '[' expression ']'	{}
	| postfix_expression '(' ')'	{}
	| postfix_expression '(' argument_expression_list ')'	{}
	| postfix_expression '.' IDENTIFIER		{}
	| postfix_expression INC_OP		{}
	| postfix_expression DEC_OP		{}
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
	| multiplicative_expression '*' unary_expression	{}
	| multiplicative_expression '/' unary_expression	{}
	| multiplicative_expression '%' unary_expression	{}
	;

additive_expression
	: multiplicative_expression	{ strcpy($$, $1); }
	| additive_expression '+' multiplicative_expression		{}
	| additive_expression '-' multiplicative_expression		{}
	;

relational_expression
	: additive_expression	{ strcpy($$, $1); }
	| relational_expression '<' additive_expression		{}
	| relational_expression '>' additive_expression		{}
	| relational_expression LE_OP additive_expression	{}
	| relational_expression GE_OP additive_expression	{}
	;

equality_expression
	: relational_expression	{ strcpy($$, $1); }
	| equality_expression EQ_OP relational_expression	{}
	| equality_expression NE_OP relational_expression	{}
	;

logical_and_expression
	: equality_expression	{ strcpy($$, $1); }
	| logical_and_expression AND_OP equality_expression		{}
	;

logical_or_expression
	: logical_and_expression	{ strcpy($$, $1); }
	| logical_or_expression OR_OP logical_and_expression	{}
	;

conditional_expression
	: logical_or_expression	{ strcpy($$, $1); }
	| logical_or_expression '?' expression ':' conditional_expression	{}
	;

assignment_expression
	: conditional_expression	{ strcpy($$, $1); }
	| unary_expression assignment_operator assignment_expression	{}
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
										tempval($1, $3);
										strcpy($$,$1);
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
	: IDENTIFIER            {strcpy($$,$1);}
	/* | '(' declarator ')' */
	// | declarator '[' ']'
	| declarator '(' parameter_list ')'	{}
	| declarator '(' identifier_list ')'	{}
	| declarator '(' ')'	{strcpy($$, $1);}
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
	: IDENTIFIER	{}
	| identifier_list ',' IDENTIFIER	{}
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

statement
	: {curr_scope++;}  compound_statement {curr_scope--;}
	| expression_statement	{}
	| selection_statement	{}
	| jump_statement		{}
	;


compound_statement
	: '{' '}'
	| '{' statement_list '}'	{}
	| '{' declaration_list '}'	{}
	| '{' declaration_list statement_list '}'	{}
	;

declaration_list
	: declaration	{}
	| declaration_list declaration	{}
	;

statement_list
	: statement	{}
	| statement_list statement	{}
	;

expression_statement
	: ';'	{}
	| expression ';'	{}
	;

selection_statement
	: IF '(' expression ')' statement statement
	| IF  '(' expression ')' statement ELSE statement statement
	;


jump_statement
	: CONTINUE ';'	{}
	| BREAK ';'	{}
	| RETURN ';'	{}
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
	: type_specifier declarator declaration_list {curr_scope++;} compound_statement {curr_scope--;}	{ lookup($2, $1, "function");}
	| type_specifier declarator {curr_scope++;} compound_statement {curr_scope--;}	{}	{ lookup($2, $1, "function");}
	| declarator declaration_list {curr_scope++;} compound_statement {curr_scope--;}	{}
	| declarator {curr_scope++;} compound_statement {curr_scope--;}	{}
	;

%%


symbol_table* initialize()
{
	symbol_table *temp = (symbol_table*)malloc(sizeof(symbol_table));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->type = (char*)malloc(sizeof(char)*10);
	temp->symbol = (char*)malloc(sizeof(char)*11);
	temp->value = (char*)malloc(sizeof(char)*10);
	strcpy(temp->value, "0");
	temp->lno = 0;
	temp->lno_used = (int*)malloc(sizeof(int));
	temp->size = 0;
	temp->next = NULL;
	temp->scope = curr_scope;
	return temp;
}

int lookup(char *s, char *type, char *token_type)
{
	if(st == NULL)
	{
		insert(s, type, token_type);
		return 0;
	}
	symbol_table *temp = st;
	while(st!=NULL)
	{
		if(strcmp(st->name, s)==0)
		{
			return 1;
		}
		st = st->next;
	}
	st = temp;
	insert(s, type, token_type);
	return 0;
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
	while(temp!=NULL)
	{
		if(strcmp(new_entry->name, temp->name)==0)
		{
			strcpy(new_entry->value, temp->value);
			deletetempval(temp);
		}
		temp = temp->next;
	}
	strcpy(new_entry->type, type);
	strcpy(new_entry->symbol, token_type);
	if(strcmp(type, "int")==0)
		new_entry->size = 4;
	else if(strcmp(type, "char")==0)
		new_entry->size = 1;
}

void tempval(char *var, char *val)
{
	tempvals *temp = (tempvals*)malloc(sizeof(tempvals));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->value = (char*)malloc(sizeof(char)*10);
	temp->next = NULL;
	strcpy(temp->name, var);
	strcpy(temp->value, val);
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
	printf("Symbol \t\t Name \t\t Type \t\t Scope \t\t Value\n");
	while(temp!=NULL)
	{
		if(strcmp(temp->name, "keyword")==0)
			printf("%s \t %s \t\t %s \t\t %d \t\t %s\n",temp->symbol, temp->name, temp->type, temp->scope, temp->value);
		else
			printf("%s \t %s \t\t %s \t\t %d \t\t %s\n",temp->symbol, temp->name, temp->type, temp->scope, temp->value);

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
	lookup("continue", "NIL", "keyword");
	lookup("break", "NIL", "keyword");
	lookup("return", "NIL", "keyword");
	yyparse();
	fclose(yyin);
	display(st);
}
