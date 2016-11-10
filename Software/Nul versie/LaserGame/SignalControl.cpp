#include "SignalControl.hpp"

SignalControl::SignalControl(IRLedController & ledController):
	ledController(ledController)
{}



void SignalControl::sendSignal(int signal){
	
//	Commands com;
//	int EncodedCommand = com.StringToBinary(&command);
	
	for(int i = 0; i < 16; i++){
		ledController.sendBit( ( (signal & (0x01 << i)) > 0) ? 1 : 0 );
		/*
		 * if( (EncodedCommand & (0x01 << i) ) > 0){
		 * 		IR.IRSet(1);
		 * }
		 *else if( (EncodedCommand & (0x01 << i) ) == 0){
		 * 		IR.IRSet(0);
		 * }
		 * 
		 */
	}
	

}





