%{

/* Declarations section */
#include <stdio.h>
#include "attributes.hpp"
#include "parser.tab.hpp"
#include "output.hpp"
using namespace std;
void errorMsg();
%}

%option yylineno
%option noyywrap

%%

void		    								{yylval.type = "VOID"; return VOID;}
int												{yylval.type = "INT"; return INT;}
byte		    								{yylval.type = "BYTE"; return BYTE;}
b												return B;
bool		    								{yylval.type = "BOOL"; return BOOL;}
and												return AND;
or			    								return OR;
not												return NOT;
true		    								return TRUE;
false											return FALSE;
return		    								return RETURN;
if												return IF;
else											return ELSE;
while		    								return WHILE;
break											return BREAK;
continue										return CONTINUE;
@pre											return PRECOND;
;												return SC;
,												return COMMA;
\(	                         					return LPAREN;
\)	                         					return RPAREN;
\{												return LBRACE;
\}												return RBRACE;
=												return ASSIGN;
\<=|\>=|==|!=|\>|\<								{yylval.name = yytext; return RELOP;}
[*]|[/]											{yylval.name = yytext; return BINOPFP;}
[+]|[-]											{yylval.name = yytext; return BINOPSP;}
[a-zA-Z][a-zA-Z0-9]*					 		{yylval.name = yytext; return ID;}
0|[1-9][0-9]*									{yylval.val = atoi(yytext); return NUM;}
\"([^\n\r\"\\]|\\[rnt\\])+\"					{yylval.name = yytext; return STRING;}
\/\/[^\r\n]*[\r|\n|\r\n]?						;
[\t\n\r ]										;
<<EOF>>											return END_OF_FILE;
.												errorMsg();
%%

void errorMsg() {
	output::errorLex(yylineno);
	exit(0);
}
