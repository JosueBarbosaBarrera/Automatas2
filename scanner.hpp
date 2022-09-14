#ifndef scanner_hpp
#define scanner_hpp

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

class scanner{
	
public:
	
	typedef enum{
		_id, _eof, _err , _nat, _real
	} token;
	
	
private:
	fstream file; //acceso a archivo
	long q; // contador de posicion desde  el inicio del archivo
	
	const int udef; // constante indefinida
	
	char reading(){return file.get();} // lee un char y avanza a la derecha y regresa
	void success(){q = file.tellg();} // mueve q a la posiocn de p, file a 
	void failure(){file.seekg(q);} // mueve p a q cuando falla
	void fallback(){file.seekg(-1, file.cur);} // u
	
	bool id(); // reconocedor
	token numeros();
	
	void wsp();
	bool eof();
	
public:	
	// constructor
	//typedef enum{
		//_id, _eof, _err
	//} token;
	
	scanner(string fname);
	
	token next();
	
};

#endif /* scanner_hpp*/
