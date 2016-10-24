//#include "hwlib.hpp"
#include "IRSensorController.hpp"
//#include "SignalControl.hpp"
//#include "rtos.hpp"

#include "CommandControl.hpp"

int main( void ){
	namespace target = hwlib::target;
	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	// wait for the PC terminal to start
	hwlib::wait_ms( 500 );
	
	auto button = target::pin_in(target::pins::d43);
	auto control_led = target::pin_out(target::pins::d42);
	
	if(!button.get()){
		control_led.set(1);
		auto pin = target::d2_36kHz();
		
		IRLed led(pin);
		
		IRLedController ledController(led);
		
		SignalControl signalController(ledController);
		
		CommandControl commandController(signalController);
		COMMAND c = COMMAND::TEST;
		
		hwlib::wait_ms(500);
		control_led.set(0);
		while(1){
			if(!button.get()){
				control_led.set(1);
				commandController.sendCommand(c);
				hwlib::wait_ms(500);
				control_led.set(0);
			}
		}
		
		
	}
	else{
		auto datapin = target::pin_in(target::pins::d8);
		
		IRSensor sensor(datapin);
		
		IRSensorController sensorController(sensor);
		
		sensorController.storeSignal();
		hwlib::cout << sensorController.getSignal();
		
		hwlib::cout << "done\n";
	
	}
	
	

	
	
	
	
	
	
	
	
	
	
//	const char* commandString = "testOn";
//	const char* test = "testOn";
//	char* testtest = (char*)test;
//	char* testCommandString = (char*)commandString;
	// IR output LED
//	auto IRLED = target::d2_36kHz();
	
//	auto IRRecieverData = target::pin_in( target::pins::d8 );
	
//	CommandEncoder irled(IRLED);
//	IRSensorController sensor(IRRecieverData);
		


//		irled.encodeCommand(&testtest);
//		sensor.IRSensorGet(&testCommandString);
//		hwlib::cout << commandString;
	}

	