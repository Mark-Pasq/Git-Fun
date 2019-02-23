#include "Card_Deck.h"
#include "Game_Participant.h"

/*
	The dealer class is the only class that has direct access of the Card_Deck.
*/

class Dealer : Game_Participant {

private:

	Card_Deck deck;

public:
	
	// constructor / destructor
	Dealer() {}
	~Dealer() {}
	
	void cardsDealt (Game_Participant* player, int howManyCards, int x);
};

