#include "hwlib.hpp"

class CommandsBTS{
private:
	int test			=	0b1101010101010101;
	int testOn			=	0b1111111111111111;
	int testOff			=	0b1000000000000000;
	const char* s2 = "test";
	const char* s3 = "testOn";
	const char* s4 = "testOff";
public:
	int my_strcmp2(char *a, char *b);
	void BinaryToString(long int input, char*** output);
};