#ifndef COMMANDCONTROL_HPP
#define COMMANDCONTROL_HPP

#include "SignalControl.hpp"

class CommandControl
{
private:
	SignalControl & signalControl;
public:
	CommandControl(SignalControl & signalControl);
	void sendCommand(COMMAND & command);
	

};

#endif // COMMANDCONTROL_HPP
