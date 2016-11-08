#include "Keypad.hpp"

Keypad::Keypad( hwlib::istream & keypadstream ):
	keypadstream( keypadstream )
{}

//	while(1) {
//		bool c = keypadstream.char_available();
//		if ( c ) {
//			listener.keyPressed( keypadstream );
//		}
//	}
