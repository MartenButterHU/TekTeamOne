#ifndef IRSENSOR_HPP
#define IRSENSOR_HPP

#include "hwlib.hpp"

namespace target = hwlib::target;

class IRSensor{
private:

	target::pin_in & diode;
//	int const active = 100000;
//	long int last_signal = hwlib::now_us() - active;
	int index = 0;
	int count_signal();
	
public:
	IRSensor(target::pin_in & diode);
	bool get();

	void IRGet(int recieve[16]);
};

#endif // IRSENSOR_HPP
