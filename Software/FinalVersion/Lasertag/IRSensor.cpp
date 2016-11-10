#include "IRSensor.hpp"


IRSensor::IRSensor(target::pin_in & diode):
	diode(diode)
{}


bool IRSensor::get(){
	return diode.get();
}



//int IRSensor::count_signal(){
//	int signal_counter = 0;
//	for(int i = 0; i < 80; i++){
//		if(diode.get() == 0){
//			signal_counter++;
//		}
//		hwlib::wait_us(10);
//	}
//	return signal_counter;
//}



//void IRSensor::IRGet(int recieve[16]){
//	int check1 = 0;
//	int check2 = 0;
//	while(1){
//		if( get() == 0 ){
//			check1 = count_signal();
//			check2 = count_signal();
//			
//			if(check1 > (check2 - 5) || check1 > (check2 + 5) ){
//				recieve[index] = 1;
//				hwlib::wait_us(800);
//			}
//			else{
//				recieve[index] = 0;
//				hwlib::wait_us(800);
//			}
//			
////			last_signal = hwlib::now_us();
//			index++;
//			check1 = 0;
//			check2 = 0;
//		}
//		else{
//			
//		}
//		if(index > 15){
////			hwlib::cout<<"\n";
//			index = 0;
//			break;
//		}
//	}
//}
