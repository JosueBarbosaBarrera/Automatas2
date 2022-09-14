
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
sp   [ \t]
nl   \n


%%



 // descipcion del scanner (lenguaje-accion)

%%

//codigo de apoyo


