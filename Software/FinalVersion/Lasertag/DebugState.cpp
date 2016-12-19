#include "DebugState.hpp"

DebugState::DebugState() {}

void DebugState::commandReadyToSend( GameControlInterface* gameControl ) {
	hwlib::cout<<"command ready to send\n";
	gameControl->sendCommand( gameControl->readCommandOut() );
}

void DebugState::dataChanged( GameControlInterface* gameControl ) {
	gameControl->updateScreen();
}

void DebugState::keyPressed( GameControlInterface* gameControl ) {
	hwlib::cout<<"keypressed\n";
	gameControl->setCommand(COMMAND::TESTON);
}

void DebugState::commandReceived( GameControlInterface* gameControl ) {
	hwlib::cout<<"FUCK YES I'VE RECEIVED SOMETHING\n";
	hwlib::cout << static_cast<unsigned int>(gameControl->readCommandIn());
}