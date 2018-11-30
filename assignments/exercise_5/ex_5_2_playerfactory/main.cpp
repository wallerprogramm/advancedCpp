#include <iostream>

#include "playfield.h"
#include "dominik_playfield.h"
#include "player.h"
#include "dominik_player.h"
#include "interactive_player.h"
#include "player_factory.h"

using namespace std;

int main(int argc, char** argv) {
	dominik_playfield field;
	bool winner = false;
	int mode = 0;

	cout << "Welcome to connect 4.\nChoose either:\n" <<
	"1 - Computer vs. Human\n" <<
	"2 - Human vs. Computer\n" <<
	"3 - Human vs. Human\n" <<
	"4 - Computer vs. Computer" << endl;

	do {
		cout << "Your choice please." << endl;
		cin >> mode;
		if (mode < 1 || mode > 4) {
			cout << "This choice is not available" << endl;
		}
	} while (mode < 1 || mode > 4);

//	player *computer = player_factory::make("dominik", playfield::player1);
//	player *interactive = player_factory::make("human", playfield::player2);
	player *p1;
	player *p2;


	switch (mode) {
		case 1 : 	p1 = player_factory::make("dominik", playfield::player1);
					p2 = player_factory::make("human", playfield::player2);
			break;
		case 2 : 	p1 = player_factory::make("human", playfield::player1);
					p2 = player_factory::make("dominik", playfield::player2);
			break;
		case 3 : 	p1 = player_factory::make("human", playfield::player1);
					p2 = player_factory::make("human", playfield::player2);
			break;
		case 4 : 	p1 = player_factory::make("dominik", playfield::player1);
					p2 = player_factory::make("dominik", playfield::player2);
			break;
		default:	cout << "Error!" << endl;
			break;
	}



	cout << "Please select a number from 1-7" << endl;
	cout << "| 1| 2| 3| 4| 5| 6| 7" << endl;
	cout << "---------------------";
	field.display();


	for (int i = 0; i < 21; i++)
	{
		field.drop_at(p1->play(field), playfield::player1);
		field.display();
		winner = field.check_won(field.get_last_move_x(), field.get_last_move_y(), 1);
		if (winner)
		{
			cout << "\nPlayer 1, you've won!" << endl;
			break;
		}

		field.drop_at(p2->play(field), playfield::player2);
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