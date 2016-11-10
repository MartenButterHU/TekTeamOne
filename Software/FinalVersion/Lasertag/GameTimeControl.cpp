#include "GameTimeControl.hpp"

GameTimeControl::GameTimeControl( GameData& data, GameControl& gameControl ):
	task( 4, "GameTimeControl" ),
	data(data),
	gameControl(gameControl)
{}

void GameTimeControl::main() {
	int time;
	rtos::clock clock(this, (1000 * rtos::ms), "clock");
	hwlib::cout<<"HOI IK BEN IN GAMETIMECONTROL\n";
	while (1) {
		wait( clock );
		data.updateTime();
		gameControl.dataChanged();
		time = data.getData( 3 );
		if ( time == 0 ) {
			break;
		}
	}
	// set flag dat het klaar is
}