#include "IRSensorController.hpp"

void test( rtos::event& e, const char* string = "" ) ;

IRSensorController::IRSensorController(IRSensor & sensor):
	task( 0, "IRSensorController" ),
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

COMMAND IRSensorController::getCommand() {

	return lastCommand;
}
