#include "OLEDControl.hpp"
#include "GameData.hpp"
#include "GameTimeControl.hpp"
#include "GameControl.hpp"
#include "IRLedController.hpp"
#include "KeypadControl.hpp"
#include "IRLed.hpp"
#include "IRSensor.hpp"
#include "IRSensorController.hpp"

int main( void ) {
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	// wait for the PC console to start
	hwlib::wait_ms( 500 );
	
	// Setup all pins for the OLED
	auto scl = hwlib::target::pin_oc( hwlib::target::pins::sda );
	auto sda = hwlib::target::pin_oc( hwlib::target::pins::scl );
	
	// Setup the pin for the IRLed
	auto IRLedPin = target::d2_36kHz();
	
	// Setup the pin for the IRSensor
	auto IRSensorPin = target::pin_in(target::pins::d8);
	
	// Setup all pins for the keypad
	auto in0  = hwlib::target::pin_in( hwlib::target::pins::a3 );
	auto in1  = hwlib::target::pin_in( hwlib::target::pins::a2 );
	auto in2  = hwlib::target::pin_in( hwlib::target::pins::a1 );
	auto in3  = hwlib::target::pin_in( hwlib::target::pins::a0 );
	auto out0 = hwlib::target::pin_oc( hwlib::target::pins::a7 );
	auto out1 = hwlib::target::pin_oc( hwlib::target::pins::a6 );
	auto out2 = hwlib::target::pin_oc( hwlib::target::pins::a5 );
	auto out3 = hwlib::target::pin_oc( hwlib::target::pins::a4 );
	
	// Setup necessary items for the screen
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
	auto oled = hwlib::glcd_oled_buffered( i2c_bus, 0x3c );
	
	// Setup necessary items for the keypad
	auto out_port = hwlib::port_oc_from_pins( out0, out1, out2, out3 );
	auto in_port = hwlib::port_in_from_pins( in0, in1, in2, in3 );
	auto matrix = hwlib::matrix_of_switches( out_port, in_port );
	auto keypadstream = hwlib::keypad< 16 >( matrix, "123A456B789C*0#D" );
	
	GameData data;
	OLEDControl _oled( oled, data );
	IRLed irLed(IRLedPin);
	IRLedController IR( irLed );
	
	IRSensor sensor( IRSensorPin );
	IRSensorController sensorController( sensor );
	
	GameControl gc(_oled, IR, sensorController );
	GameTimeControl timer( data, gc );
	KeypadControl keypad( keypadstream, gc );
	
	rtos::run();
}
