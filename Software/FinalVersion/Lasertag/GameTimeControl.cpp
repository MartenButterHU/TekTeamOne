#include "GameTimeControl.hpp"

GameTimeControl::GameTimeControl( GameData& data, OLEDControl& oled ):
	task( "GameTimeControl"),
	data(data),
	oled(oled)
{}

void GameTimeControl::main() {
	int time;
	rtos::clock clock(this, (1000 * rtos::ms), "clock");
	while (1) {
		wait( clock );
		data.updateTime();
		oled.dataChanged();
		time = data.getData( 3 );
		if ( time == 0 ) {
			break;
		}
	}
	// set flag dat het klaar is
}