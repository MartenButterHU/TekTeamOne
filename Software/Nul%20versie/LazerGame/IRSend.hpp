#include "hwlib.hpp"
#include "IRCommands.hpp"

class IRSend{
private:
	hwlib::target::pin_out outputPin;
	hwlib::target::pin_out showPin;
public:
	IRSend(hwlib::target::pin_out & outputPin, hwlib::target::pin_out & showPin):
		outputPin(outputPin),
		showPin(showPin)
	{}
	
	void SendCommand(char* s){
		
		int BitToBe;
		
		for(int i = 0; i < 15; i++){
			if(BitToBe > 0){
				outputPin.set( 1 );
				showPin.set( 1 );
				hwlib::wait_µs(1600);
				outputPin.set( 0 );
				showPin.set( 0 );
				hwlib::wait_µs(800);
			}
			else{
				outputPin.set( 1 );
				showPin.set( 1 );
				hwlib::wait_µs(800);
				outputPin.set( 0 );
				showPin.set( 0 );
				hwlib::wait_µs(1600);
			}
		}
	}
};

//0 = 800 µs aan en 1600 µs uit
//1 = 1600 µs aan en 800 µs uit