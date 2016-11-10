#include "IRLedController.hpp"


IRLedController::IRLedController(IRLed & led):
	task( 1, "IRLedController" ),
	commandChannel( this, "commandChannel" ),
	IRLedTimer( this, "IRLedTimer" ),
	led(led)
{}

void IRLedController::main() {
	while(1) {
		int command = commandChannel.read();
		sendCommand( command );
		hwlib::cout<<"\ncommandsend\n";
		IRLedTimer.set( 3 * rtos::ms );
		wait( IRLedTimer );
		sendCommand( command );
	}
}

void IRLedController::sendBit( bool state) {
	if( state == 1 ) {
		IRLedTimer.set( 1600 * rtos::us );
		led.on();
		wait( IRLedTimer );
		IRLedTimer.set( 800 * rtos::us );
		led.off();
		wait( IRLedTimer );
	}
	else {
		IRLedTimer.set( 800 * rtos::us );
		led.on();
		wait( IRLedTimer );
		IRLedTimer.set( 1600 * rtos::us );
		led.off();
		wait( IRLedTimer );
	}
	
}

void IRLedController::writeCommand( int command ) {
	commandChannel.write( command );
}

void IRLedController::sendCommand( int command ){
	for(int i = 0; i < 16; i++) {
			sendBit( ( (command & (0x01 << i)) > 0) ? 1 : 0 );
	}
}




