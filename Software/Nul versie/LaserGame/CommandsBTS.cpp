#include "CommandsBTS.hpp"

int strcmp2(char* a, const char *b){
    while (*a && *b && *a == *b){ 
		++a; 
		++b; 
	}
    return *a - *b;
}

void CommandsBTS::BinaryToString(long int input, char*** output){
	char* s1 = (char*)&output;
	if(strcmp2(s1, s2)==0){
		output = (char***)&s2;
	}
	else if(strcmp2(s1, s3)==0){
		output = (char***)&s3;
	}
	else if(strcmp2(s1, s4)==0){
		output = (char***)&s4;
	}
	else{
//		hwlib::cout << "Command not found!";
	}
	
}
