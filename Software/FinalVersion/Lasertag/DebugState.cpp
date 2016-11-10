#include "DebugState.hpp"

DebugState::DebugState() {}

void DebugState::commandReadyToSend( GameControlInterface* gameControl ) {
	hwlib::cout<<"command received\n";
	gameControl->sendCommand( gameControl->readCommand() );
}

void DebugState::dataChanged( GameControlInterface* gameControl ) {
	gameControl->updateScreen();
}

void DebugState::keyPressed( GameControlInterface* gameControl ) {
	hwlib::cout<<"keypressed";
	gameControl->setCommand(COMMAND::HALLO);
}