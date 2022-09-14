#include <iostream>
#include <stdio.h>
#include "scanner.hpp"

using namespace std;

int main(int argc, const char * argv[]){
	scanner scan("prueba.txt");
	
	scanner::token t;
	
	do{
		t = scan.next();
		
		switch(t){
			case scanner::_id: cout << "identificador \n"; break;
			case scanner::_nat: cout << "natural \n"; break;
			case scanner::_real: cout << "real \n"; break;
			case scanner::_eof: cout << "fin de archivo \n"; break;
			case scanner::_err: cout << "Error \n";
			
			default: cout << "WTF \n";
		}
		
	}while(t != scanner::_err && t != scanner::_eof);

    return 0;
}
