%{
#include"y.tab.h"
#include<stdio.h>
#include<string.h>
int LineNo=1;
%}
identifier [a-zA-Z][_a-zA-Z0-9]*
number [0-9]+|([0-9]*\.[0-9]+)
%%
"if" {return IF;}
"else" {return ELSE;}
"int"|"char"|"float" {return TYPE_SPEC;}
{identifier} {strcpy(yylval.var,yytext);return VAR;}
{number} {strcpy(yylval.var,yytext);return NUM;}
\<|\>|\>=|\<=|==|!= {strcpy(yylval.var,yytext);return RELOP;}
[ \t] ;
\n LineNo++;
. return *yytext;
%%
