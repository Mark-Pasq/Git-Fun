#include "Cards.h"

#include <cstdlib>
#include <ctime>

class Card_Deck {

public:

	// constructor / destructor
	Card_Deck() {};
	~Card_Deck() {};
	
	int cardsDealt();
	// This takes two random cards from 0 to 51 as indexes and swaps them
	// and essentially shuffling the cards.
	void shuffleTheCards();
	Cards getCards(int player);

private:
	
	const static int deckLength = 52;

	// This is the array of cards
	Cards cards[deckLength];
	int iter = 0;
};

