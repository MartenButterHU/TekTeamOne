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
//   
//	// switch which enables the 36 kHz output
////	auto sw = target::pin_in( target::pins::d43 );
//   
//	// when the switch is pressed, 
//	// repeat sending 1 ms signal and 1 ms silence
//	// and show this on the LED
//
//	auto tsop_signal = target::pin_in( target::pins::d8 );
//	auto tsop_gnd    = target::pin_out( target::pins::d9 );
//	auto tsop_vdd    = target::pin_out( target::pins::d10 );
//	tsop_gnd.set( 0 );
//	tsop_vdd.set( 1 );
//   
//	auto led         = target::pin_out( target::pins::d22 );
//   
//	auto const active = 100'000;
//	auto last_signal = hwlib::now_us() - active;
//	
////	int sizeBitPatern = 15;
//	int numberOfRecievedBits = 0;
//	int bitPaternRecieved[15];
//	int savedBitPaternRecieved[15];
//	
//	
//	for(;;){
//		
//		if( ( (last_signal + active ) > hwlib::now_us() ) && numberOfRecievedBits < 15){
//			led.set(1);
//			bitPaternRecieved[numberOfRecievedBits] = 1;
//			numberOfRecievedBits++;
//		}
//		else if( ( (last_signal + active ) < hwlib::now_us() ) && numberOfRecievedBits < 15){
//			led.set(0);
//			bitPaternRecieved[numberOfRecievedBits] = 0;
//			numberOfRecievedBits++;
//		}
//		else if(numberOfRecievedBits == 15){
//			for(int i = 0; i < 15; i++){
//				if(bitPaternRecieved[i] != savedBitPaternRecieved[i]){
//					for(int j = 0; j < 15; j++){
//						hwlib::cout << bitPaternRecieved[j];
//						savedBitPaternRecieved[j] = bitPaternRecieved[j];
//					}
//					hwlib::cout << "\n";
//				}
//			}
//			numberOfRecievedBits = 0;
//			led.set(0);
//		}
//			
//		if( tsop_signal.get() == 0 ){
//			last_signal = hwlib::now_us();
//		}
//	}
//}