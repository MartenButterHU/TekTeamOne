#ifndef IRSENSORCONTROLLER_HPP
#define IRSENSORCONTROLLER_HPP

#include "rtos.hpp"
#include "IRSensor.hpp"
#include "COMMANDS.hpp"


///Processes the signal
class IRSensorController : public rtos::task<>
{
private:
	rtos::pool<COMMAND> lastCommand;
	IRSensor& sensor;
	
	int count_signal();
	
	void main();
public:
	IRSensorController(IRSensor & sensor);
	
	COMMAND getSignal();
	void storeSignal();

};

#endif // IRSENSORCONTROLLER_HPP
