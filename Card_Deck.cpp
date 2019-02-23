#include "Card_Deck.h"

#include <iostream>

Card_Deck::Card_Deck() {

	int index = 0;
	// random
	std::srand(time(0));

	for (int cardValue = 1; cardValue <= 13; cardValue++) {

		for (int newCard = 0; newCard < 4; newCard++) {

			// If the value is 1, then it is an ace
			if (cardValue == 1) {

				this -> cards[index].cardIsAce = true;
			}
			
			// For any other card greater than a 10, their values are 10.
			if (cardValue < 10) {
				
				this -> cards[index].cardValue = cardValue;
			}
			
			else {
				this -> cards[index].cardValue = 10;
			}
			
			index++;
		}
	}
	this -> shuffleTheCards;
}

int Card_Deck::cardsDealt()
{
	return 0;
}

void Card_Deck::shuffleTheCards() {

	int random1;
	int random2;
	Cards temp;

	for (int i = 0; i < deckLength / 2; i++) {

		// Get 2 random card indexes
		random1 = std::rand() % deckLength;
		random2 = std::rand() % deckLength;

		// Now swap the cards
		temp = this -> cards[random1];
		this -> cards[random1] = this -> cards[random2];
		this -> cards[random2] = temp;
	}
}

Cards Card_Deck::getCards(int player)
{
	return Cards();
}

Cards Card_Deck::getCards(int player) {

	this -> iter++;

	// If player == 0, then the dealer is getting dealt his hand
	if (player == 0) {

		// You will only show the dealers card every other time
		if (iter % 2 == 0) {

			std::cout << "Dealer " << "You were dealt an " << this -> cards[iter].cardValue << std::endl;
		}
		else {

			std::cout << player << "You were deal an " << this -> cards[iter].cardValue << std::endl;
		}
		return this -> cards[iter];
	}

}
