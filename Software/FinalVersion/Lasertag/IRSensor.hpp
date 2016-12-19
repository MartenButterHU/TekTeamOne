#ifndef IRSENSOR_HPP
#define IRSENSOR_HPP

#include "hwlib.hpp"

namespace target = hwlib::target;

class IRSensor {
private:
	///Data pin of the sensor
	//
	///When there is an IR signal, this pin becomes low(active low).
	target::pin_in & diode;
	
public:
	///IRSensor constructor method
	//
	///Takes the data pin diode as an argument.
	IRSensor(target::pin_in & diode);
	
	///Returns sensor value
	//
	///The sensor is active low. Return false when detecting IR and true when there is no signal present.
	bool get();
};

#endif // IRSENSOR_HPP
