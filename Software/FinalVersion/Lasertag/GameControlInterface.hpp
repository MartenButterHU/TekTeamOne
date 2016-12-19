#ifndef GAMECONTROLINTERFACE_HPP
#define GAMECONTROLINTERFACE_HPP

#include "COMMANDS.hpp"
#include "IRSensorController.hpp"

class GameControlInterface
{
public:
	virtual char readKey() = 0;
	virtual void updateScreen() = 0;
	virtual void sendCommand( COMMAND ) = 0;
	virtual void setCommand( COMMAND ) = 0;
	virtual COMMAND readCommandOut() = 0;
	virtual COMMAND readCommandIn() = 0;
	virtual void commandReceivedIn( IRSensorController* ) = 0;
};

#endif // GAMECONTROLINTERFACE_HPP
