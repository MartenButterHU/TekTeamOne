#ifndef IRSENSOR_HPP
#define IRSENSOR_HPP

#include "hwlib.hpp"

namespace target = hwlib::target;

class IRSensor {
private:

	target::pin_in & diode;
	int index = 0;
	//int count_signal();
	
public:
	IRSensor(target::pin_in & diode);
	bool get();

	//void IRGet(int recieve[16]);
};

#endif // IRSENSOR_HPP
