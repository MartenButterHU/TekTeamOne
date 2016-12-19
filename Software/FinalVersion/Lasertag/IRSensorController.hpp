#ifndef IRSENSORCONTROLLER_HPP
#define IRSENSORCONTROLLER_HPP

#include "rtos.hpp"
#include "IRSensor.hpp"
#include "COMMANDS.hpp"
#include "commandListener.hpp"


///Processes the signal
class IRSensorController : public rtos::task<>
{
private:
	rtos::pool<COMMAND> lastCommand;
	IRSensor& sensor;
	
	commandListener* listenerArray[10];
	int arrayHead = 0;
	unsigned int signalToBinary();
	
	void notifyListeners();
	
	void main();
public:
	IRSensorController(IRSensor & sensor);
	
	COMMAND getCommand();
	void storeSignal();
	///Add a listener for the sensor
	//
	///When using a listener pattern use this method to add a listener
	void addListener( commandListener* listener );
};

#endif // IRSENSORCONTROLLER_HPP
