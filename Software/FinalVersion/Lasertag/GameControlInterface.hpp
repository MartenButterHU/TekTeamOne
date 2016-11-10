#ifndef GAMECONTROLINTERFACE_HPP
#define GAMECONTROLINTERFACE_HPP

#include "COMMANDS.hpp"

class GameControlInterface
{
public:
	virtual char readKey() = 0;
	virtual void updateScreen() = 0;
	virtual void setCommand( COMMAND ) = 0;
	virtual COMMAND readCommand() = 0;
	virtual void sendCommand( COMMAND ) = 0;
	virtual void commandReceived() = 0;
};

#endif // GAMECONTROLINTERFACE_HPP
