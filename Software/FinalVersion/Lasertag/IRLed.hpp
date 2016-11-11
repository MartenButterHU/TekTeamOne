#ifndef IRLED_HPP
#define IRLED_HPP

#include "hwlib.hpp"

namespace target = hwlib::target;

///IRLed software interface
//
///THe class that models an IRLed in code.
class IRLed
{
private:
	target::d2_36kHz diode;
public:
	///Constructor
	IRLed(target::d2_36kHz & diode);
	
	
	///Turn led on
	void on();
	///Turn led off
	void off();

};



#endif // IRLED_HPP
