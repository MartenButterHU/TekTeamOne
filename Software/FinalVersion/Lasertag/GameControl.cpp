#include "GameControl.hpp"

void test( rtos::event& e, const char* string = "" ) {
	e.print( hwlib::cout<<" ["<<string<<"] "<<'\n' );
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
	test( keyChannel );
	keyChannel.write( c );
	test( keyChannel );
}

void GameControl::updateScreen() {
	oled.dataChanged();
}

void GameControl::sendCommand( COMMAND command ) {
	test( commandChannel );
	irLedController.writeCommand(static_cast<int>(command));
	test( commandChannel );
}

void GameControl::setCommand( COMMAND command ) {
	test( commandChannel );
	commandChannel.write( command );
	commandReceived();
	test( commandChannel );
}

void GameControl::commandReceived() {
	currentState.commandReceived( this );
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
			currentState.keyPressed( this );
		}
		else if ( w == dataChangedFlag ) {
			currentState.dataChanged( this );
		}
	}
}