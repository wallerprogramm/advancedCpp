#include <iostream>

#include "playfield.h"
#include "dominik_playfield.h"
#include "player.h"
#include "dominik_player.h"
#include "interactive_player.h"

using namespace std;

int main(int argc, char** argv) {
	dominik_playfield field;
	bool winner = false;

	dominik_player computer(playfield::player1);
	interactive_player inter(playfield::player2);

	cout << "Please select a number from 1-7" << endl;
	cout << "| 1| 2| 3| 4| 5| 6| 7" << endl;
	cout << "---------------------";
	field.display();


	for (int i = 0; i < 21; i++)
	{
		field.drop_at(computer.play(field), playfield::player1);
		field.display();
		winner = field.check_won(field.get_last_move_x(), field.get_last_move_y(), 1);
		if (winner)
		{
			cout << "\nPlayer 1, you've won!" << endl;
			break;
		}

		field.drop_at(inter.play(field), playfield::player2);
		field.display();
		winner = field.check_won(field.get_last_move_x(), field.get_last_move_y(), 2);
		if (winner)
		{
			cout << "\nPlayer 2, you've won!" << endl;
			break;
		}
	}

	return 0;
}