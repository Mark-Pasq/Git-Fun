#include "Dealer.h"
#include "Player.h"

#include <iostream>

bool Is_the_game_ovah (Game_Participant* x, int player);
bool Did_anyone_win (Player* arrayOfPlayers[], int arrayLength);

int main() {

	Dealer dealer;
	int numberOfPlayers;
	int varTemp;
	bool gameOvah;
	char playerOption;

	std::cout << "Hello and welcome to my table, where we will be playing standard BlackJack" << std::endl;
	std::cout << "How many players are at the table? " << std::endl;

	std::cin >> numberOfPlayers;
	Player* player (arrayOfPlayers[]);

	// Loop creates the new players and takes their wagers
	for (int i = 0; i < numberOfPlayers; i++) {

		std::cout << "Please place your game wagers now " << i + 1 << std::endl;
		arrayOfPlayers[i] = new Player();
		std::cin >> varTemp;
		arrayOfPlayers[i] -> setMyWager(varTemp);
	}

	// Now the players will get their first 2 cards
	for (int i = 0; i < numberOfPlayers; i++) {

		dealer.cardsDealt (arrayOfPlayers[i], 2, i + 1);
		std::cout << std::endl;
	
		// Dealer gets his initial 2 cards here
		dealer.cardsDealt (&dealer, 2, 0);
		std::cout << std::endl;
	}

	while (!gameOvah) {

		// Here we check to see if any player has won
		for (int i = 0; i < numberOfPlayers; i++) {

			if (Is_the_game_ovah (arrayOfPlayers[i], i + 1)) {

				gameOvah = true;
				continue;

			}
		}
		
		// Here we check to see if the dealer has won the hand
		if (Is_the_game_ovah (&dealer, 0)) {

			gameOvah = true;
			continue;
		}
		
		for (int i = 0; i < numberOfPlayers; i++) {

			if (arrayOfPlayers[i] -> getiBust()) {

				i++;
				continue;
			}
			
			std::cout << "Your turn player " << i + 1 << "Choose 'H' to take a hit, or 'S' to stand!" << std::endl;
			std::cin >> playerOption;

			if (playerOption == 'H') {

				dealer.cardsDealt (arrayOfPlayers[i], 1, i + 1);
			}
		}

		if (Did_anyone_win (arrayOfPlayers, numberOfPlayers)) {

			gameOvah = true;
			continue;
		}

		// Here the dealer gets his turn to play his hand.  He has to hit on 16 and stand on 17
		if (dealer.getTotalPoints() < 17) {

			dealer.cardsDealt (&dealer, 1, 0);
			std::cout << std::endl;
		}
		return 0;
	}

	bool Is_the_game_ovah (Game_Participant* x, int player) {

		// He we check if the person that is playing the game has won the hand
		if (x -> getGameStatus()) {

			std::cout << "Player" << player << "has won the hand.  Congratulations" << x->getPointTotal() << std::endl;
			return true;
		}

		if (player == 0 && x-> getiBust()) {

			std::cout << "The dealer has bust" << "win" << x -> getPointTotal() << std::endl;
		}

		return false;
	}

	bool Did_anyone_win (player* arrayOfPlayers[], int arrayLength) {

		for (int i = 0; i < arrayLength; i++) {

			// Here we check to see if anyone is still in the game
			if (arrayOfPlayers[i] -> getTotalPoints(), 21) {

				return false;
			}
			return true;
		}
	}
}

bool Is_the_game_over(Game_Participant * x, int player)
{
	return false;
}

bool Did_anyone_win(Player * arrayOfPlayers[], int arrayLength)
{
	return false;
}
