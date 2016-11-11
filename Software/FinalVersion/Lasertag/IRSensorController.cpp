#include "IRSensorController.hpp"

void test( rtos::event& e, const char* string = "" ) ;

IRSensorController::IRSensorController(IRSensor & sensor):
	task( 0, "IRSensorController" ),
	signalChannel( this, "signalChannel" ),
	IRSensorTimer( this, "IRSensorTimer" ),
	sensor(sensor)
{}

void IRSensorController::main() {
	unsigned int initialMessage;
	unsigned int redundantMessage;
	while(1) {
		///De sensor is active low, dus wordt er hier gewacht op een lage waarde.
		if( sensor.get() == 0 ) {
			
			if(!initial){
				initialMessage = signalToBinary();
				sleep (2500 *rtos::us);
			}
			else{
				if(initialMessage == signalToBinary){
					Decoder d(initialMessage);
					lastCommand = d.get();
				}
				initialMessage = 0;
			}
		}
		sleep(400 * rtos::us);
	}
}


unsigned int IRSensorController::signalToBinary() {
	int index = 15;
	int signalCounter = 1;
	unsigned volatile int signal= 0;
	while(index >= 0){
		sleep(400 * rtos::us);
		if(!sensor.get()){
			signalCounter++;
		}
		else{
			signal &= (signalCounter >= 4) << index;
		}
	}
	return signal;
}


void IRSensorController::storeSignal() {
	int check
	
	
	1 = 0;
	int check2 = 0;
	while(1){
		int index = 0;
		if(index > 15){
			index = 0;
			break;
		}
		else if( sensor.get() == 0 ) {
			check1 = count_signal();
			check2 = count_signal();
			
			if(check1 > (check2 - 5) || check1 > (check2 + 5) ) {
				signalChannel.write( 1 );
				sleep(800 * rtos::us);
			}
			else {
				signalChannel.write( 0 );
				sleep(800 * rtos::us);
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
