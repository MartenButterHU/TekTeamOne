#include "KeypadControl.hpp"

KeypadControl::KeypadControl( hwlib::keypad< 16 >& keypad, GameControl& gameControl ) :
	task( 2, "KeypadControl" ),
	keypadTimer( this, "keypadTimer" ),
	keypad( keypad ),
	gameControl( gameControl )
{}

void KeypadControl::main() {
	while(1) {
		keypadTimer.set( 100 * rtos::ms );
		wait(keypadTimer);
		if ( keypad.char_available() ) {
			gameControl.keyPressed( keypad.getc() );
		}
	}
}