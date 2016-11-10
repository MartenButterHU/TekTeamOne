#ifndef GAMETIMECONTROL_HPP
#define GAMETIMECONTROL_HPP

#include "hwlib.hpp"
#include "rtos.hpp"
#include "GameControl.hpp"
#include "GameData.hpp"

class GameTimeControl : public rtos::task<>
{
private:
	GameData& data;
	GameControl& gameControl;
	void main();
public:
	GameTimeControl( GameData& data, GameControl& gameControl );
};

#endif // GAMETIMECONTROL_HPP
