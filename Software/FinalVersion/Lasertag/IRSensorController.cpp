#include "IRSensorController.hpp"

IRSensorController::IRSensorController(IRSensor & sensor):
	task( 0, "IRSensorController" ),
	sensor(sensor)
{}

void IRSensorController::main() {
	unsigned int initialMessage = 0;
	while(1) {
		///De sensor is active low, dus wordt er hier gewacht op een lage waarde.
		if( sensor.get() == 0 ) {
			if ( initialMessage == 0 ) {
				initialMessage = signalToBinary();
				sleep( 2500 *rtos::us );
			}
			else{
				if(initialMessage == signalToBinary()){
					hwlib::cout<<"SIGNAL CORRECT\n";
					hwlib::cout<<hwlib::bin<<initialMessage<<'\n';
					lastCommand.write(static_cast<COMMAND>(initialMessage));
					notifyListeners();
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
	unsigned volatile int signal = 0;
	while( index >= 0 ) {
		for( int i = 0; i < 6; i++) {
			sleep(400 * rtos::us);
			if( sensor.get() == 0 ){
				signalCounter++;
			}
		}
		signal |= (signalCounter >= 3) << index;
		index--;
		signalCounter = 0;
	}
	return signal;
}

void IRSensorController::notifyListeners() {
	for(int i = 0; i < arrayHead; i++) {
		listenerArray[arrayHead] -> commandReceivedIn( this );
	}
}

COMMAND IRSensorController::getCommand() {
	return lastCommand.read();
}

void IRSensorController::addListener( commandListener* _listener ) {
	if (arrayHead < 10) {
		listenerArray[arrayHead] = _listener;
		arrayHead += 1;
	}
}