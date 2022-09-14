#include "scanner.hpp"

#include <iostream>
#include <stdio.h>
using namespace std;

scanner::scanner(string fname): udef(-1), file(fname){}

bool scanner::id(){
	int actual = 0;
	int prior = udef;
	
	while(actual!=udef){
		prior = actual;
		char c = reading();
		
		switch(actual){
			case 0:
				actual = isalpha(c) ? 2 : c == "_" ? 1 : udef;
				break;
				// if (isalpha(c)) actual = 2;
				// else if (c == "_") actual = 1;
				// else actual = udef;
			case 1:
				actual = isdigit(c) || c == "_" ? 1 : isalpha(c) ? 2 : udef;
				break;
				//if (isdigit(c)  or c == "_");
				//else if (isalpha(c)) actual = 2;
				//else actual = udef;
			case 2:
				actual = isalnum(c) || c == "_" ? 2 : udef;
		}
	}
	if (prior == 2) {
		fallback();
		success();
		return true;
	}
	
	failure();
	return false;
}

// reconocedor de numeros

scanner::token scanner::numeros(){
	int actual = 0;
	int prior = udef;
	
	while(actual!=udef){
		prior = actual;
		char c = reading();
		
		switch(actual){
			case 0: actual == isdigit(c) ? 1 : udef; break;
			case 1: actual == isdigit(c) ? 1 : c == "." ? 2 : udef; break;
			case 2:
			case 3: actual == isdigit(c) ? 3 : udef; break;
		}
	}
	if (prior == 1 || prior == 3) {
		fallback();
		success();
		
		return prior == 1 _nat : _real;
	}
	
	failure();
	return _err;
}

//////


void scanner::wsp(){
	//lectura de spacios en blanco
	while(isspace(reading()));
	fallback();
	success();
}

bool scanner::eof(){
	return !file.eof();
}

// buscador secuencial
scanner::token scanner::next(){
	// solo devuelven el tipo de lexema
	wsp();
	
	if (id()) return _id;
	token t = numeros();
	if (t == _nat) return _nat;
	else if (t == _real) return _real;
	
	if (eof()) return _eof;
	
	return _err;
	
}
