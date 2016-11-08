#ifndef GAMETIMECONTROL_HPP
#define GAMETIMECONTROL_HPP

#include "hwlib.hpp"
#include "rtos.hpp"
#include "OLEDControl.hpp"
#include "GameData.hpp"

class GameTimeControl : public rtos::task<>
{
private:
	GameData& data;
	OLEDControl& oled;
	void main();
public:
	GameTimeControl( GameData& data, OLEDControl& oled );
};

#endif // GAMETIMECONTROL_HPP
