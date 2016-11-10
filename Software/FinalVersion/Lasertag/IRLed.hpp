#ifndef IRLED_HPP
#define IRLED_HPP

#include "hwlib.hpp"

namespace target = hwlib::target;

class IRLed
{
private:
	target::d2_36kHz diode;
public:
	IRLed(target::d2_36kHz & diode);
	void on();
	void off();

};



#endif // IRLED_HPP
