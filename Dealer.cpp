#include "Dealer.h"

void Dealer::cardsDealt (Game_Participant* player, int howManyCards, int x) {
	
	for (int i = 0; i < howManyCards; i++) {

		card tempcard = deck.getCards (x);
		player -> addToList (tempcard);
		player -> setTotalPoints (tempcard.cardValue, x);

	}
}