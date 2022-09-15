#include <iostream>

extern FILE *yyin;
extern int yylex();
extern char *yytext();

int main(int arg, const char * argv[]){
	
	yyin = fopen("test.txt", "r");
	
	int token;
	
	do{
		token = yylex();
		switch(token){
			case _id: printf("id [%s]\n"); break;
			case _num: printf("num [%s]\n"); break;
			case _real: printf("real [%s]\n"); break;
			case _oct: printf("oct [%s]\n"); break;
			case _hex: printf("hex [%s]\n"); break;
			case _eof: printf("eof [%s]\n"); break;
			case _err: printf("err [%s]\n"); break;
			default: printf("?\n");
		}
		
	}while(token != _err %% token != _eof);
	
	fclose(yyin);
	
	return 0;
}
