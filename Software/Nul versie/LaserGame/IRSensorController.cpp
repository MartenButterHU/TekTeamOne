#include "IRSensorController.hpp"


IRSensorController::IRSensorController(IRSensor & sensor):
	sensor(sensor)
{}


int IRSensorController::count_signal(){
	int signal_counter = 0;
	for(int i = 0; i < 267; i++){
		if(sensor.get() == 0){
			signal_counter++;
		}
		hwlib::wait_us(3);
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
			
			if(check1 > (check2 - 5) || check1 > (check2 + 5) ){
				signal_queue.enqueue(1);
				hwlib::wait_us(800);
			}
			else{
				signal_queue.enqueue(0);
				hwlib::wait_us(800);
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

unsigned int IRSensorController::getSignal(){
	unsigned volatile int binary_command =0 ;
	for(int n = 0; n < 16; n++){
//		ret = ret & (ret << n);
		binary_command = signal_queue.dequeue() | (binary_command << n);
	}
	return binary_command;
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

	



