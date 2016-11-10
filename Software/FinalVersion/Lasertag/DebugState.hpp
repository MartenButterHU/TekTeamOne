#ifndef DEBUGSTATE_HPP
#define DEBUGSTATE_HPP

#include "GameStateInterface.hpp"
#include "hwlib.hpp"

class DebugState : public GameStateInterface {
public:
	DebugState();
	void keyPressed( GameControlInterface* gameControl );
	void commandReceived( GameControlInterface* gameControl );
	void dataChanged( GameControlInterface* gameControl );
};

#endif // DEBUGSTATE_HPP
