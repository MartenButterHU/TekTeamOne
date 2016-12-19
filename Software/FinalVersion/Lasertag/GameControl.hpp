#ifndef GAMECONTROL_HPP
#define GAMECONTROL_HPP

#include "rtos.hpp"
#include "hwlib.hpp"
#include "GameStateInterface.hpp"
#include "GameControlInterface.hpp"
#include "StateCollection.hpp"
#include "OLEDControl.hpp"
#include "IRLedController.hpp"
#include "IRSensorController.hpp"
#include "commandListener.hpp"

class GameControl : public rtos::task<>, GameControlInterface, public commandListener
{
private:
	StateCollection sc;
	rtos::flag dataChangedFlag; //Flag die wordt gezet voor commands
	rtos::channel< char, 1 > keyChannel;
	rtos::channel< COMMAND, 50 > commandChannelOut;
	rtos::channel< COMMAND, 50 > commandChannelIn;
	rtos::flag commandFlag;
	GameStateInterface& currentState;
	OLEDControl& oled;
	IRLedController& irLedController;
	IRSensorController& irSensorController;
	void main();
public:
	GameControl( OLEDControl& oled, IRLedController& irLedController, IRSensorController& irSensorController );
	char readKey();
	void keyPressed( char c );
	void updateScreen();
	void sendCommand( COMMAND command );
	void setCommand( COMMAND command );
	COMMAND readCommandOut();
	COMMAND readCommandIn();
	void commandReadyToSend();
	void dataChanged();
	void commandReceivedIn( IRSensorController* sensorControl );
};

#endif // GAMECONTROL_HPP