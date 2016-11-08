#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

class GameData
{
private:
	int playerID;
	int weapon;
	int score = 100;
	int gameTime; // gameTime in seconds
public:
	/// Get Data
	//
	/// getData can be utilised to get the data specified with
	/// the integer that is given.
	/// 0 stands for: playerID
	/// 1 stands for: weapon
	/// 2 stands for: score
	/// 3 stands for: gameTime
	int getData( int dataToGet );
	
	/// Set Data
	//
	/// Uses the same integer values as getData but can only access
	/// the playerID, weapon and gameTime and sets the data accordingly.
	void setData( int dataToSet, int data );
	
	/// Update Score
	//
	/// When the score needs to be changed it can be done using this
	/// function. It will substract the amount of lostPoints of the 
	/// total value of score
	void updateScore( int lostPoints );
	
	/// Update Time
	//
	/// This function gets called when there needs to be a update of the
	/// gameTime, this will occur every second.
	void updateTime();
};

#endif // GAMEDATA_HPP
