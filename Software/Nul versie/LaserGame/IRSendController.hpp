#include "IRSend.hpp"

class IRSendController{
private:
	hwlib::target::d2_36kHz		outputPin;
	hwlib::target::pin_out		showPin;
public:
	IRSendController(hwlib::target::d2_36kHz & outputPin, hwlib::target::pin_out & showPin):
		outputPin(outputPin),
		showPin(showPin)
	{}
	void sendCommand(const IRCommands & command){
		IRSend send( outputPin, showPin);
		send.SendCommand(command);
	}
	
};