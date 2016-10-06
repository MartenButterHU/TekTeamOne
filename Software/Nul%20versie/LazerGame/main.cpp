#include "hwlib.hpp"
#include "IRSendController.hpp"
#include "IRRecieve.hpp"

int main( void ){
	namespace target = hwlib::target;
	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
   
	// wait for the PC terminal to start
	hwlib::wait_ms( 500 );
	
	// IR output LED
	auto IRLED = target::d2_36kHz();
	// red output LED to test if a bit is sended
	auto red = target::pin_out( target::pins::d42 );

	auto IRRecieverData		= target::pin_in( target::pins::d8 );
	auto IRRecieverGND			= target::pin_out( target::pins::d9 );
	auto IRRecieverVLT			= target::pin_out( target::pins::d10 );
	//set a GND and Volt pin
	IRRecieverGND.set( 0 );
	IRRecieverVLT.set( 1 );
	
	//green output LED to test if a bit is recieved
	auto led = target::pin_out( target::pins::d22 );
	
	IRRecieve IRGet(IRRecieverData, led);
	
	IRSendController send(IRLED, red);
		
	while(1){
		hwlib::cout << IRRecieverData.get();
		led.set(IRRecieverData.get());
		hwlib::wait_ms(100);
		led.set(0);
		hwlib::wait_ms(100);
	}
}
	