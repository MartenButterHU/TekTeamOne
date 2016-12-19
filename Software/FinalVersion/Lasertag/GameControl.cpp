#include "GameControl.hpp"

void test( rtos::event& e, const char* string = "" ) {
	e.print( hwlib::cout );
	hwlib::cout<<" ["<<string<<"] "<<'\n';
}

GameControl::GameControl( OLEDControl& oled, IRLedController& irLedController, IRSensorController& irSensorController ) :
	task( 3, "GameControl" ),
	dataChangedFlag( this, "dataChangedFlag" ),
	keyChannel( this, "keyChannel" ),
	commandChannelOut( this, "commandChannelOut" ),
	commandChannelIn( this, "commandChannelIn" ),
	commandFlag(this, "commandFlag"),
	currentState ( sc.dbstate ),
	oled(oled),
	irLedController(irLedController),
	irSensorController( irSensorController)
{}

char GameControl::readKey() {
	return keyChannel.read();
}

void GameControl::keyPressed( char c ) {
	keyChannel.write( c );
}

void GameControl::updateScreen() {
	oled.dataChanged();
}

void GameControl::sendCommand( COMMAND command ) {
	irLedController.writeCommand(static_cast<int>(command));
}

void GameControl::setCommand( COMMAND command ) {
	commandChannelOut.write( command );
	commandReadyToSend();
}

void GameControl::commandReadyToSend() {
	currentState.commandReadyToSend( this );
}

COMMAND GameControl::readCommandOut() {
	return commandChannelOut.read();
}

COMMAND GameControl::readCommandIn() {
	return commandChannelIn.read();
}

void GameControl::dataChanged() {
	dataChangedFlag.set();
}

void GameControl::commandReceivedIn( IRSensorController* sensorControl ) {
	commandChannelIn.write( sensorControl->getCommand() );
	commandFlag.set();
}

void GameControl::main() {
	while(1) {
		rtos::event w = wait( keyChannel + dataChangedFlag + commandFlag );
		if ( w ==  keyChannel ) {
			keyChannel.read(); // MEEGEVEN WELKE KEY ER GEREAD WORDT?
			currentState.keyPressed( this );
		}
		else if ( w == dataChangedFlag ) {
			currentState.dataChanged( this );
		}
		else if ( w == commandFlag ) {
			currentState.commandReceived( this );
		}
	}
}