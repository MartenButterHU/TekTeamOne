#include "IRSensor.hpp"


IRSensor::IRSensor(target::pin_in & diode):
	diode(diode)
{}


bool IRSensor::get(){
	return diode.get();
}


