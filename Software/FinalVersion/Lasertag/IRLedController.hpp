#ifndef IRLEDCONTROLLER_HPP
#define IRLEDCONTROLLER_HPP

#include "hwlib.hpp"
#include "rtos.hpp"
#include "IRLed.hpp"



class IRLedController : public rtos::task<> {
private:
	rtos::channel< int, 10 > commandChannel;
	rtos::timer IRLedTimer;
	IRLed & led;
	void sendBit(bool state);
	void main();
public:
	IRLedController(IRLed & led);
	void writeCommand( int command );
	void sendCommand( int command );

};


#endif // IRLEDCONTROLLER_HPP
