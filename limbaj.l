%{
#include <stdio.h>
#include "y.tab.h"
%}
NATZ	[1-9][0-9]*

INT_POZ		{NATZ}|0

REAL_POZ	{INT_POZ}\.[0-9]+

TXT		\"[^"\n]*\"

TIMES	[xX]
%%
"!"		{return LOGICAL_NOT;}

"="		{return EQ;}
"<"		{return LT;}
"<="	{return LTE;}
">"		{return GT;}
">="	{return GTE;}
"<>"	{return NEQ;}

"?!"	{return BGIN;} 
"$"		{return END;} 

{TIMES} 	{return TIMES;}

"Bool"	{ return BOOL;}
"Int"	{ return INT;}
"Real"	{ return REAL;}
"Text" 	{ return TEXT;}

{INT_POZ}	{ return INT_POZ;}
{REAL_POZ}	{return REAL_POZ;}
{TXT}	{ return TEXT_VAL;}

"if"	{return IF;}
"then"	{return THEN;}
"else"	{return ELSE;}

"for"	{return FOR;}
"while"	{return WHILE;}
"do" 	{return DO;}

"print"		{return PRINT;}
"Factorial"		{return FACTORIAL;}
"Max"		{return MAX;}

"inc"	{return INC;}
"dec"	{return DEC;}
"^"		{return TO_UPPER;}

"over"	{return RET;}

"true"	{ return BOOL_VAL;}
"false" { return BOOL_VAL;} /*valori de baza bool*/	

"use"	{return USE;}/*pt user types*/
"into"	{return INTO;}/*la fel*/

[A-Z](_|[A-Z]|[0-9])*	{ return CONST_ID;}/*recunoastere de tipuri dupa nume*/

[a-z](_|[a-z]|[0-9])* 	{ return VAR_ID;}

u[A-Z][a-z]+	{ return USER_TYPE;}

([A-Z][a-z]+)+	{ return FUNC_ID;}
"->"	{return RIGHT_ARROW;} /*la functii pt tip return*/

":" {return ASSIGN;}

[ \t] ;

\n {yylineno++;}

. {return yytext[0];}


