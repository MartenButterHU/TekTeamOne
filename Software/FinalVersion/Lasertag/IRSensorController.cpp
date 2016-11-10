#include "IRSensorController.hpp"


IRSensorController::IRSensorController(IRSensor & sensor):
	task( 0, "IRSensorController" ),
	signalChannel( this, "signalChannel" ),
	IRSensorTimer( this, "IRSensorTimer" ),
	sensor(sensor)
{}

void IRSensorController::main() {
	while(1) {
		if( !sensor.get() ) {
			hwlib::cout<<"There is a signal\n";
			storeSignal();
		}
		IRSensorTimer.set( 400 * rtos::us );
		wait( IRSensorTimer );
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


void IRSensorController::storeSignal(){
	int check1 = 0;
	int check2 = 0;
	while(1){
		if( sensor.get() == 0 ){
			hwlib::cout <<"signaal ontvangen";
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
		else{
			
		}
		if(index > 15){
//			hwlib::cout<<"\n";
			index = 0;
			break;
		}
	}
}

COMMAND IRSensorController::getSignal(){
	unsigned volatile int binary_command;
	for(int n = 0; n < 16; n++){
//		ret = ret & (ret << n);
		binary_command = signalChannel.read() | ( binary_command << n );
	}
	return static_cast< COMMAND >(binary_command);
}


//void IRSensorController::IRSensorGet(char** commandString){
//	IRSensor sensor(diode);
//	
//	while(bitStream[0] != 1){
//		sensor.IRGet(bitStream);
//	}
//	
//	for(int i = 0; i < 16; i++){
//		if(bitStream[i] > 0){
//			BitStreamAsInt += CurrentBitValue;
//		}
//		CurrentBitValue /= 2;
//	}
//	CurrentBitValue = 65536;
//	
//	CommandsBTS com;
//	com.BinaryToString(BitStreamAsInt, &commandString);
//	
//}
