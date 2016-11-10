#include "GameControl.hpp"

void test( rtos::event& e, const char* string = "" ) {
	e.print( hwlib::cout );
	hwlib::cout<<" ["<<string<<"] "<<'\n';
}

GameControl::GameControl( OLEDControl& oled, IRLedController& irLedController, IRSensorController& irSensorController ) :
	task( 3, "GameControl" ),
	dataChangedFlag( this, "dataChangedFlag" ),
	keyChannel( this, "keyChannel" ),
	commandChannel( this, "commandChannel" ),
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
	commandChannel.write( command );
	commandReadyToSend();
}

void GameControl::commandReadyToSend() {
	currentState.commandReadyToSend( this );
}

COMMAND GameControl::readCommand() {
	return commandChannel.read();
}

void GameControl::dataChanged() {
	dataChangedFlag.set();
}

void GameControl::main() {
	while(1) {
		rtos::event w = wait( keyChannel + dataChangedFlag );
		if ( w ==  keyChannel ) {
			keyChannel.read(); // MEEGEVEN WELKE KEY ER GEREAD WORDT?
			currentState.keyPressed( this );
		}
		else if ( w == dataChangedFlag ) {
			currentState.dataChanged( this );
		}
	}
}