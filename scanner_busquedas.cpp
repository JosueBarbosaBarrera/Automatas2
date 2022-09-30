#include "parser.hpp"
// busqueda
bool parser::exp(){
	//ealv del token, etrada
	if(t == scanner:l_lap or t == scanner::_eof or t == scanner::__neg){
		return term() and exp(); // 
	}
	return false
}



bool parser::exp_(){
	//eval del token, etrada
	if(t == scanner::_sum)	return match(scanner:::_sum) and exp(); //
	if(t == scanner::_rpar or t == sacnner::_eof)	return true // 
	
	return false;
	
}


bool parser::term(){
	//eval del token, etrada
	if(t == scanner::_lpar or t === sacnner::_eof or t::sacnner::_neg)	return fact() and term_() // 
	
	return false;
	
}

bool parser::term_(){
	//eval del token, etrada
	if(t == scanner::_times )	return match(scanner::_times ) and term() // 
	if(t == scanner::_sum or t == scanner::_rpar or t== scanner::_eof )	return true; // 
	
	return false;
	
}


bool parser::fact(){
	//eval del token, etrada
	if(t == scanner::_times )	return match(scanner::_times ) and term() // 
	if(t == scanner::_sum or t == scanner::_rpar or t== scanner::_eof )	return; // 
	
	return false;
	
}


bool parser::parser()
{
	s.reset();
	t = s.next();
	bool resultado = exp();
	
	
	
	return false;
}




