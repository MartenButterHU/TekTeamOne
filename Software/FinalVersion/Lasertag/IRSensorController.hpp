#ifndef IRSENSORCONTROLLER_HPP
#define IRSENSORCONTROLLER_HPP

#include "rtos.hpp"
#include "IRSensor.hpp"
#include "COMMANDS.hpp"


///Processes the signal
class IRSensorController : public rtos::task<>
{
private:

	//
	rtos::pool<COMMAND> lastCommand;
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
	
	COMMAND getSignal();
	void storeSignal();

};

#endif // IRSENSORCONTROLLER_HPP
