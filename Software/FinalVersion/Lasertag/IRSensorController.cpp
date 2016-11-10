#include "IRSensorController.hpp"

void test( rtos::event& e, const char* string = "" ) ;

IRSensorController::IRSensorController(IRSensor & sensor):
	task( 0, "IRSensorController" ),
	signalChannel( this, "signalChannel" ),
	IRSensorTimer( this, "IRSensorTimer" ),
	sensor(sensor)
{}

void IRSensorController::main() {
	while(1) {
		///De sensor is active low, dus wordt er hier gewacht op een lage waarde.
		if( sensor.get() == 0 ) {
			
		}
		sleep(400 * rtos::us);
	}
}


int IRSensorController::count_signal() {
	int signal_counter = 0;
	for(int i = 0; i < 267; i++){
		if(sensor.get() == 0){
			signal_counter++;
		}
		IRSensorTimer.set( 3 * rtos::us );
		wait( IRSensorTimer );
	}
	return signal_counter;
}


void IRSensorController::storeSignal() {
	int check1 = 0;
	int check2 = 0;
	while(1){
		if(index > 15){
//			hwlib::cout<<"\n";
			index = 0;
			break;
		}
		else if( sensor.get() == 0 ) {
			check1 = count_signal();
			check2 = count_signal();
			
			if(check1 > (check2 - 5) || check1 > (check2 + 5) ) {
				signalChannel.write( 1 );
				IRSensorTimer.set( 800 * rtos::us );
				wait( IRSensorTimer );
			}
			else {
				signalChannel.write( 0 );
				IRSensorTimer.set( 800 * rtos::us );
				wait( IRSensorTimer );
			}
			
//			last_signal = hwlib::now_us();
			index++;
			check1 = 0;
			check2 = 0;
		}
	}
}

COMMAND IRSensorController::getSignal() {
	unsigned volatile int binary_command;
	for(int n = 0; n < 16; n++){
		binary_command = signalChannel.read() | ( binary_command << n );
	}
	return static_cast< COMMAND >(binary_command);
}
