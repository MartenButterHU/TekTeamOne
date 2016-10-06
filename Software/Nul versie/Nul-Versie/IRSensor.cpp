#include "IRSensor.hpp"

using namespace IR;


IRSensor::IRSensor():
	data_pin(data_pin)
{}

bool IRSensor::get(){
	return !data_pin.get();
}
