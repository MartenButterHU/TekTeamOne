#ifndef IRSENSORCONTROLLER_HPP
#define IRSENSORCONTROLLER_HPP

#include "rtos.hpp"
#include "IRSensor.hpp"
#include "COMMANDS.hpp"

class IRSensorController : public rtos::task<>
{
private:
	rtos::channel<int,16> signalChannel;
	rtos::timer IRSensorTimer;
	IRSensor& sensor;
	
	unsigned int volatile signal;
	volatile int index = 0;
	int BitStreamAsInt = 0;
	int bitStream[16];
	int count_signal();
	
	void main();
public:
	IRSensorController(IRSensor & sensor);

	//void IRSensorGet(char** commandString);
	
	COMMAND getSignal(); //<---WHAT ISHJ DEZAAH?!
	void storeSignal();

};

#endif // IRSENSORCONTROLLER_HPP
