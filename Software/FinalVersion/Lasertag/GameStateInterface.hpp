#ifndef GAMESTATEINTERFACE_HPP
#define GAMESTATEINTERFACE_HPP

#include "GameControlInterface.hpp"
#include "COMMANDS.hpp"

class GameStateInterface {
public:
	virtual void commandReadyToSend( GameControlInterface* gameControl ) = 0;
	virtual void keyPressed( GameControlInterface* gameControl ) = 0;
	virtual void dataChanged( GameControlInterface* gameControl ) = 0;
	virtual void commandReceived( GameControlInterface* gameControl ) = 0;
};

#endif // GAMESTATEINTERFACE_HPP
