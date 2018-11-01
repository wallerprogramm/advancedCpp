#include <iostream>
#include "playfield.h"
#include "player.h"
#include "alphonse_player.h"
#include "CPKili.h"


using namespace std;

int main(int argc, char** argv) {
    playfield field;
    bool winner = false;
    player<playfield> computer(playfield::player2);
    player<playfield> pc(playfield::player1);
    alphonse::player<playfield> alphi(playfield::player1);
    CPKili<playfield> kili(playfield::player2);

    cout << "Please select a number from 1-7" << endl;
    cout << "| 1| 2| 3| 4| 5| 6| 7" << endl;
    cout << "---------------------";
    field.display();


    for (int i = 0; i < 21; i++)
    {
//        field.drop(playfield::player1);
        field.drop_at(pc.play(field), playfield::player1);
//        field.drop_at(alphi.play(field), playfield::player1);
//        field.drop_at(kili.play(field), playfield::player1);
        field.display();
        winner = field.check_won(field.get_last_move_x(), field.get_last_move_y(), 1);
        if (winner)
        {
            cout << "\nPlayer 1, you've won!" << endl;
            break;
        }

        field.drop(playfield::player2);
//        field.drop_at(computer.play(field), playfield::player2);
//        field.drop_at(alphi.play(field), playfield::player2);
//        field.drop_at(kili.play(field), playfield::player2);
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