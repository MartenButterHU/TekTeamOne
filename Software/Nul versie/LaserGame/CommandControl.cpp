#include "CommandControl.hpp"

CommandControl::CommandControl(SignalControl & signalControl):
	signalControl(signalControl)
{}


void CommandControl::sendCommand(COMMAND & command){
	signalControl.sendSignal(static_cast<int>(command));
}