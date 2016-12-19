#ifndef IRLEDCONTROLLER_HPP
#define IRLEDCONTROLLER_HPP

#include "hwlib.hpp"
#include "rtos.hpp"
#include "IRLed.hpp"


///Led Controller
//
/// Class that controls the sending of a binary signal in the specified format.
class IRLedController : public rtos::task<> {
private:
	///Command channel
	//
	///The channel on which another proces can place a binary signal
	rtos::channel< int, 10 > commandChannel;
	
	///Led interface
	IRLed & led;
	
	///Methode for sending a single bit
	void sendBit(bool state);
	
	///Send signal method
	//
	/// Send command from channel head
	void sendCommand( int command );
	
	///The ledcontroller proces
	void main();
	
public:
	///LedController constructor method
	//
	///Takes the led that needs to be controlled as an argument.
	IRLedController(IRLed & led);
	
	///Send binary signal method
	//
	///This is the method that can be called to write a command in the signal channel
	void writeCommand( int command );
};


#endif // IRLEDCONTROLLER_HPP
