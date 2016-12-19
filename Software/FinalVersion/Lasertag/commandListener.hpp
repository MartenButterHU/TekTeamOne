#ifndef COMMANDLISTENER_HPP
#define COMMANDLISTENER_HPP

#include "IRSensorController.hpp"

class IRSensorController;

class commandListener
{
public:
	virtual void commandReceivedIn(  IRSensorController* sensorControl ) = 0;
};

#endif // GAMECONTROL_HPP