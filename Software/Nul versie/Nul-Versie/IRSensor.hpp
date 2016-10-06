#ifndef IRSENSOR_HPP
#define IRSENSOR_HPP

using namespace hwlib::target;

namespace IR
{

class IRSensor
{
private:
	pin_in & data_pin;	
public:
	IRSensor(pin_in & data_pin);
	
	bool get();

};

}

#endif // IRSENSOR_HPP
