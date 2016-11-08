#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "hwlib.hpp"
#include "KeypadControl.hpp"

class Keypad
{
private:
	hwlib::istream & keypadstream;
	
public:
	/// Keypad constructor
	//
	/// This will construct a keypad using the given ports, it
	/// uses the hwlib::keypad class as a ingoing stream
	Keypad( hwlib::istream & keypadstream );
};

#endif // KEYPAD_HPP
