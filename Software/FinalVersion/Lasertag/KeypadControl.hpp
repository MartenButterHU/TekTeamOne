#ifndef KEYPADCONTROL_HPP
#define KEYPADCONTROL_HPP

#include "hwlib.hpp"
#include "rtos.hpp"
#include "GameControl.hpp"

class KeypadControl : public rtos::task<>
{
private:
	void main();
	hwlib::keypad& keypad;
	GameControl& gameControl;
public:
	KeypadControl( hwlib::keypad& keypad, GameControl& gameControl );
	
};

#endif // KEYPADCONTROL_HPP
