#ifndef KEYPADCONTROL_HPP
#define KEYPADCONTROL_HPP

#include "GameControl.hpp"

class KeypadControl : public rtos::task<>
{
private:
	rtos::timer keypadTimer;
	hwlib::keypad< 16 >& keypad;
	GameControl& gameControl;
	void main();
public:
	KeypadControl( hwlib::keypad< 16 >& keypad, GameControl& gameControl );
	
};

#endif // KEYPADCONTROL_HPP
