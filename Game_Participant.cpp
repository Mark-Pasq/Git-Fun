#include "Game_Participant.h"

#include <iostream>


bool Game_Participant::getGameStatus() {

	return this -> Did_I_win_the_game;
}

void Game_Participant::setGameStatus (bool game_status) {

	this -> Did_I_win_the_game = game_status;
}

bool Game_Participant::getiBust() {

	return this -> ibust;
}

int Game_Participant::getTotalPoints() {

	return this -> pointtotal;
}

void Game_Participant::setTotalPoints (int add_my_points, int x) {

	this -> pointtotal += add_my_points;
	
	if (this -> pointtotal == 21) {

		this -> Did_I_win_the_game = true;
	}
	
	if (this -> pointtotal > 21) {

		std::cout << "Too bad " << x << "! You bust and you're out of the game. See you soon, if you dare" << std::endl;
		this -> ibust = true;
	}
	
	if (x != 0) {

		if (this->pointtotal % 2 == 0) {

			std::cout << x << "Your point total is " << this->pointtotal << std::endl;
		}
	} else {

		std::cout << "Dealer!" << x << "Your point total is " << this->pointtotal << std::endl;
		
	}
}
