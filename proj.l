D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include<string.h>
#include "y.tab.h"

void count();
void comment();
void scomment();
void new_line();
int check_type();

int line_number=1;
%}

%%
"/*"			{ comment(); }
"//"		{ scomment(); }

"break"			{ count(); return(BREAK); }
"char"			{ count(); return(CHAR); }
"continue"		{ count(); return(CONTINUE); }
"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"float"			{ count(); return(FLOAT); }
"if"			{ count(); return(IF); }
"while"			{ count(); return(WHILE); }
"do"			{ count(); return(DO); }
"int"			{ count(); return(INT); }
"long"			{ count(); return(LONG); }
"return"		{ count(); return(RETURN); }
"short"			{ count(); return(SHORT); }
"sizeof"		{ count(); return(SIZEOF); }
"void"			{ count(); return(VOID); }
"include"		{count(); return(INCLUDE);}
"h"				{count(); return(H);}

{L}({L}|{D})*		{ count(); return(check_type()); }

[\'][.][\']		{ count(); return(CHAR_CONSTANT); }
{D}+{IS}?		{ count(); return(INT_CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); return(CONSTANT); }

{D}+{E}{FS}?		{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(FLOAT_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(FLOAT_CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }

"#"				{count(); return(HASH);}
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }
"\n"		{ count(); new_line(); }
[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%

yywrap()
{
	return(1);
}

void new_line()
{
	line_number++;
}
void comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		continue;

	if ((c1 = input()) != '/' && c != 0)
	{
		/* unput(c1); */
		goto loop;
	}

}

void scomment()
{
	char c, c1;
	while((c=input()) !='\n'  && c!=0)
		continue;
		/* putchar(c); */
	if(c!=0)
		putchar('\n');

}

int column = 0;

void count()
{
	strcpy(yylval.string,yytext);
	int i;
	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
	ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/
	/* printf("IDENTIFIER"); */
	return(IDENTIFIER);
}
/*
int main()
{
	yyin = fopen("program.c", "r");
	yylex();
	fclose(yyin);
} */
