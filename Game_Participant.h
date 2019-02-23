#ifndef _Game_Participant.H_
#define _Game_Participant.H_

#include "Cards.h"

#include <list>

class Game_Participant {

public:

	// constructor / destructor
	Game_Participant() {};
	~Game_Participant() {};

	void addToList (Cards c) {

		cards.push_back(&c);
	}

	bool getGameStatus();
	void setGameStatus (bool status);
	void setTotalPoints (int pointtotal, int x);
	bool getiBust();
	int getTotalPoints();

protected:
	std::list<Cards*> cards;
	bool Did_I_win_the_game = false;
	bool ibust = false;
	int pointtotal = 0;

};
#endif

