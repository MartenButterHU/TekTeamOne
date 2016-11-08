#ifndef OLEDCONTROL_HPP
#define OLEDCONTROL_HPP

#include "hwlib.hpp"
#include "rtos.hpp"
#include "GameData.hpp"

class OLEDControl : public rtos::task<>
{
private:
	hwlib::glcd_oled_buffered oled;
	GameData& data;
	rtos::flag dataChangedFlag;
	void main();
public:
	/// Constructor
	//
	/// Constructs an OLED Control, the first param is the oled itself
	/// and the second param is the GameData from who the OLEDControl
	/// needs to get it's information
	OLEDControl( hwlib::glcd_oled_buffered oled, GameData& data );
	
	/// Data Change
	//
	/// Whenever there is a data change the OLED will update
	/// it's data and display it on screen
	void updateScreen();
	
	void dataChanged();
};

#endif // OLEDCONTROL_HPP
