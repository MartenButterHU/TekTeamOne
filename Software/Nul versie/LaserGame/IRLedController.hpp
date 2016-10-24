#ifndef IRLEDCONTROLLER_HPP
#define IRLEDCONTROLLER_HPP

#include "hwlib.hpp"
#include "IRLed.hpp"



class IRLedController{
private:
	IRLed & led;
public:
	IRLedController(IRLed & led);
	void sendBit(bool state);

};


#endif // IRLEDCONTROLLER_HPP
