//#include "hwlib.hpp"
//
//int main( void ){
//	namespace target = hwlib::target;
//	
//	// kill the watchdog
//	WDT->WDT_MR = WDT_MR_WDDIS;
//   
//	// wait for the PC terminal to start
//	hwlib::wait_ms( 500 );
//   
//	// IR output LED
//	auto ir = target::d2_36kHz();
//   
//	// red output LED
//	auto red = target::pin_out( target::pins::d42 );
//   
//
////	int sizeBitPatern = 15;
//	int BitPatern[] = {0,0,0,0,0,0,1,1,0,1,1,1,0,1,1};
//	int i = 0;
//   
//	for(;;){
//		hwlib::wait_ms( 1 ); 
//		
//		ir.set((BitPatern[i] > 0) ? 1 : 0);
//		red.set((BitPatern[i] > 0) ? 1 : 0);
//		
//		hwlib::wait_ms( 1 );
//		
//		i++;
//		ir.set( 0 );
//	}
//}