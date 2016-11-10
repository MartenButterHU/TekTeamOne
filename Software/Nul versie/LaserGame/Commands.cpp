#include "Commands.hpp"

int strcmp(char* a, const char *b){
    while (*a && *b && *a == *b){ 
		++a; 
		++b; 
	}
    return *a - *b;
}
//
//int Commands::StringToBinary(char*** s){
//	char* s1 = (char*)&s;
//
//	if(strcmp(s1, s2 ) == 0){
//		return test;
//	}
//	else if(strcmp(s1 , s3) == 0 ){
//		return testOn;
//	}
//	else if(strcmp(s1 , s4) == 0){
//		return testOff;
//	}
//	else{
//		
////		hwlib::cout << "Command not found!\n";
//		return 0;
//	}
//	
//}

