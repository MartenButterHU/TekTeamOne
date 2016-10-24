#include "IRLedController.hpp"


IRLedController::IRLedController(IRLed & led):
	led(led)
{}

void IRLedController::sendBit(bool state){
//		IRLed led(diode);

	if(state == 1){
//		hwlib::cout << "send 1\n";
		led.on();
		hwlib::wait_us(1600);
		led.off();
		hwlib::wait_us(800);
	}
	else{
//		hwlib::cout << "send 0\n";
		led.on();
		hwlib::wait_us(800);
		led.off();
		hwlib::wait_us(1600);
	}
	
}





