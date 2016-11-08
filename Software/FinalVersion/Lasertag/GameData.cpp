#include "GameData.hpp"

int GameData::getData( int dataToGet )
{
	if ( dataToGet == 0 ) {
		return playerID;
	}
	
	else if ( dataToGet == 1 ) {
		return weapon;
	}
	
	else if ( dataToGet == 2 ) {
		return score;
	}
	
	else if ( dataToGet == 3 ) {
		return gameTime;
	}
	return 0;
}

void GameData::setData( int dataToSet, int data ) {
	if ( dataToSet == 0 ) {
		playerID = data;
	}
	
	else if ( dataToSet == 1 ) {
		if ( data > 5 ) {
			// hier een error melding?
		}
		else { 
			weapon = data;
		}
	}
	
	else if ( dataToSet == 3 ) {
		if ( data > 600 ) {
			// hier een error melding?
		}
		else {
			gameTime = data;
		}
	}
}

void GameData::updateScore( int lostPoints )
{
	score -= lostPoints;
	if ( score <= 0 ) {
		// set hier de bool van run game naar 'dood'
	}
}

void GameData::updateTime() {
	gameTime -= 1;
	if ( gameTime == 0 ) {
		// make sure everything stops using a flag or something?
	}
}