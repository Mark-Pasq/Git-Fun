#include "Game_Participant.h"

class Player : Game_Participant {

private:

	int myWager;

public:
	
	// constructor / destructor
	Player() {};
	~Player() {};
	
	void setMyWager(int Wager);
	int getMyWager();

};

