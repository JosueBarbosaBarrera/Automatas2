
%{
// codigo c
#include "scanner.h"
int line = 1;
%}

 //definicion de languajes
A   [a-zA-Z]
N   [0-9]
H   {N}[a-fA-F]
O	[0-7]

id 	({A}|_(_|{N})*{A})(_|{N}|{A})*

octa 0{O}*
hexa 0x({H}{2})+

num  [1-9]{N}*
real (0|[1-9]{N}*)"."{N}+
sp   [ \t]
nl   \n


%%

 // descipcion del scanner (lenguaje-accion)

{id}	return _id;
{real}	return _real;
{octa}	return _oct;
{hexa}	return _hex;

{num}	return _num;


{sp}	;
{nl}	line++;

<<EOF>>	return _eof;

.		{printf("linea %i: Error [%c]\n", line, *yytext);
		return _err;
		}

%%

//codigo de apoyo

int yywrap() { return 1; }
