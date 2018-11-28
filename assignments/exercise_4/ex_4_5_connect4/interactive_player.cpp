#include <iostream>

#include "interactive_player.h"

using namespace std;

int interactive_player::play(const playfield &field) {
	int choice;
	cout << "\nPlayer" << player_id << ", please select a number from 1 - 7: ";
	cin >> choice;

	//Error Checking

	if (cin.fail()) {
		cout << "Error!";
		exit(1);
	}

	while (choice > playfield::width || choice <= 0 || field.stoneat(choice - 1, 0) != playfield::none) {
		cout << "\nPlease select again: ";
		cin >> choice;
	}

	return choice - 1;
}

interactive_player::interactive_player(int p_id) : player_id(p_id){

}

interactive_player::~interactive_player() {}