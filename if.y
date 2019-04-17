%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct quad
{
	char op[5];
	char arg1[10];
	char arg2[10];
	char result[10];
}quad;

quad QUAD[30];

typedef struct stack
{
	int items[100];
	int top;
}stack;
stack stk;

int Index = 0;


extern FILE *yyin;
void AddQuadruple(char op[5],char arg1[10],char arg2[10],char result[10]);
%}

%union
{
	char var[10];
}

%token <var> NUM VAR RELOP
%token IF TYPE_SPEC ELSE
%type <var> EXPR ASSIGNMENT RELEXPR
%left '-' '+'
%left '*' '/'

%%

START : CODE
			;
BLOCK: '{' CODE '}'
			;
CODE :  BLOCK
			| STATEMENT CODE
			| STATEMENT
			;
STATEMENT : DECLARATION ';' | ASSIGNMENT ';' | CONDITIONAL_STMT ;

DECLARATION : TYPE_SPEC VAR_LIST ;

VAR_LIST : VAR ',' VAR_LIST | VAR ;

ASSIGNMENT : VAR '=' EXPR{
			strcpy(QUAD[Index].op,"=");
			strcpy(QUAD[Index].arg1,$3);
			strcpy(QUAD[Index].arg2,"");
			strcpy(QUAD[Index].result,$1);
			strcpy($$,QUAD[Index++].result);
			} ;

CONDITIONAL_STMT : IF '(' RELEXPR ')' BLOCK
										| IF '(' RELEXPR ')' BLOCK ELSE BLOCK
										;

EXPR : EXPR '+' EXPR {AddQuadruple("+" , $1, $3, $$); }
     | EXPR '-' EXPR {AddQuadruple("-" , $1, $3, $$); }
     | EXPR '*' EXPR {AddQuadruple("*" , $1, $3, $$); }
     | EXPR '/' EXPR	{AddQuadruple("/" , $1, $3, $$); }
     | '-' EXPR {strcpy($$, $2);}
     | '(' EXPR ')'      {strcpy($$, $2);}
     | VAR
     | NUM
     ;
RELEXPR: VAR RELOP RELEXPR {AddQuadruple($2,$1,$3,$$);}
	   | NUM RELOP RELEXPR {AddQuadruple($2,$1,$3,$$);}
	   | VAR
	   | NUM
	   ;

%%

void AddQuadruple(char op[5],char arg1[10],char arg2[10],char result[10])
{
	strcpy(QUAD[Index].op,op);
	strcpy(QUAD[Index].arg1,arg1);
	strcpy(QUAD[Index].arg2,arg2);
	sprintf(QUAD[Index].result,"t%d",Index++);
	strcpy(result,QUAD[Index++].result);
}

int main(int argc,char *argv[])
{
	FILE *fp;
	int i;
	fp=fopen("text.txt","r");
	yyin=fp;
	yyparse();
	printf("Three Address Code Quadruple");
	printf("\n\t%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s","pos","op","arg1","arg2","result");
	printf("\n\t-----------------------------------------------------------------------");
	for(i=0;i<Index;i++)
	{
		printf("\n\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s", i,QUAD[i].op, QUAD[i].arg1,QUAD[i].arg2,QUAD[i].result);
	}
	printf("\n\n");
	return 0;
}
