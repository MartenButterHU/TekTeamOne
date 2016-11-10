#include "OLEDControl.hpp"

OLEDControl::OLEDControl( hwlib::glcd_oled_buffered& oled, GameData& data ) :
	oled(oled),
	data(data)
{}

void OLEDControl::updateScreen() {
	int playerID = data.getData( 0 );
	int weapon = data.getData( 1 );
	int score = data.getData( 2 );
	int gameTime = data.getData( 3 );

	int minutes = gameTime / 60;
	int seconds = gameTime - (minutes*60);
	
	auto w1 = hwlib::window_part( 
		oled, 
		hwlib::location( 0, 0 ),
		hwlib::location( 128, 32));
	auto w2 = hwlib::window_part( 
		oled, 
		hwlib::location( 0, 32 ),
		hwlib::location( 128, 32));

	auto f1 = hwlib::font_default_8x8();
	auto d1 = hwlib::window_ostream( w1, f1 );

	auto f2 = hwlib::font_default_8x8();
	auto d2 = hwlib::window_ostream( w2, f2 );

	d1 << "\f"
		<< "Lasergame" << "\n" 
		<< "TekTeamOne" << "\n"
		<< "Weapon: " << weapon << "\n" 
		<< "player: "<< playerID;
		
	d2 << "\f"
		<< "==============\n"
		<< "Time: " << minutes << ":" << seconds << "\n"
		<< "score: " << score << "\n"
		<< "==============\n";
	//oled.flush();
}

void OLEDControl::dataChanged() {
	updateScreen();
}