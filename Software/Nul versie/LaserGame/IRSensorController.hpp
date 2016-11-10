#ifndef IRSENSORCONTROLLER_HPP
#define IRSENSORCONTROLLER_HPP

#include "hwlib.hpp"
#include "IRSensor.hpp"
#include "CommandsBTS.hpp"
#include "Queue.hpp"


namespace target = hwlib::target;

class IRSensorController{
private:
	IRSensor & sensor;
	Queue<int,16> signal_queue;
	unsigned int volatile signal;
	volatile int index =0;
	int BitStreamAsInt = 0;
	int bitStream[16];
	int count_signal();
public:
	IRSensorController(IRSensor & sensor);

	//void IRSensorGet(char** commandString);
	
	unsigned int getSignal(); //<---WHAT ISHJ DEZAAH?!
	void storeSignal();

};

#endif // IRSENSORCONTROLLER_HPP
