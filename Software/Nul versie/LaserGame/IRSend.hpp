#include "hwlib.hpp"
#include "IRCommands.hpp"

class IRSend{
private:
	hwlib::target::d2_36kHz		outputPin;
	hwlib::target::pin_out		showPin;
public:
	IRSend(hwlib::target::d2_36kHz & outputPin, hwlib::target::pin_out & showPin):
		outputPin(outputPin),
		showPin(showPin)
	{}
	
	void write(const IRCommands & command){
		int bitToBe = (int)&command;
		for (int j = 0; j < 15; j++){
			if( ( bitToBe & (0x01 << j) ) > 0 ){
				outputPin.set( 1 );
				showPin.set( 1 );
				hwlib::wait_us(1600);
				outputPin.set( 0 );
				showPin.set( 0 );
				hwlib::wait_us(800);
			}
			else{
				outputPin.set( 1 );
				showPin.set( 1 );
				hwlib::wait_us(800);
				outputPin.set( 0 );
				showPin.set( 0 );
				hwlib::wait_us(1600);
				
			}
		}
	}
};

//0 = 800 µs aan en 1600 µs uit
//1 = 1600 µs aan en 800 µs uit