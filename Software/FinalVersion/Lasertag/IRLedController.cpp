#include "IRLedController.hpp"


IRLedController::IRLedController(IRLed & led):
	task( 1, "IRLedController" ),
	commandChannel( this, "commandChannel" ),
	led(led)
{}

void IRLedController::main() {
	while(1) {
		int command = commandChannel.read();
		sendCommand( command );
		sleep( 3 * rtos::ms );
		sendCommand( command );
	}
}

void IRLedController::sendBit( bool state ) {
	if( state == 1 ) {
		led.on();
		sleep( 1600 * rtos::us );
		led.off();
		sleep( 800 * rtos::us );
	}
	else {
		led.on();
		sleep( 800 * rtos::us );
		led.off();
		sleep( 1600 * rtos::us );
	}
	
}

void IRLedController::writeCommand( int command ) {
	commandChannel.write( command );
}

void IRLedController::sendCommand( int command ){
	for(int i = 15; i >= 0; i--) {
		sendBit( ( (command & (0x01 << i)) > 0) ? 1 : 0 );
	}
}
