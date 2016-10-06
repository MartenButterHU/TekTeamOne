#include "hwlib.hpp"

int main( void ){
	namespace target = hwlib::target;
	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
   
	// wait for the PC terminal to start
	hwlib::wait_ms( 500 );

	auto tsop_signal = target::pin_in( target::pins::d8 );
	auto tsop_gnd    = target::pin_out( target::pins::d9 );
	auto tsop_vdd    = target::pin_out( target::pins::d10 );
	
	tsop_gnd.set( 0 );
	tsop_vdd.set( 1 );
   
	auto led         = target::pin_out( target::pins::d22 );
   
	auto const active = 100'000;
	

		
	while(1){
		hwlib::cout << tsop_signal.get();
		hwlib::wait_ms(100);
	}
}
	