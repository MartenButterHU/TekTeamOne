#ifndef COMMANDENCODER_HPP
#define COMMANDENCODER_HPP


#include "IRLedController.hpp"
#include "Commands.hpp"



class SignalControl{
private:
	//Commands & com;
	IRLedController & ledController;
	
public:
	SignalControl(IRLedController & ledController);
	void sendSignal(int signal);
	//void encodeCommand(char** command);
	

};
#endif // COMMANDENCODER_HPP
