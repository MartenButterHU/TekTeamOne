#ifndef IRLED_HPP
#define IRLED_HPP

#include <hwlib.hpp>


using namespace hwlib::target

namespace IR
{

class IRLed
{
private:
	d2_36kHz & diode;
public:

	IRLed(d2_36kHz &);
	
	void on();
	void off();

};

}

#endif // IRLED_HPP
