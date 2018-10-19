#include "playfield.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    playfield field;
    bool winner = false;

    cout << "Please select a number from 1-7" << endl;
    cout << "| 1| 2| 3| 4| 5| 6| 7" << endl;
    cout << "---------------------";
    field.display();

    for (int i = 0; i < 21; i++)
    {
        field.drop(1);
        field.display();
        winner = field.check_won(field.get_last_move_x(), field.get_last_move_y(), 1);
        if (winner)
        {
            cout << "\nPlayer 1, you've won!" << endl;
            break;
        }

        field.drop(2);
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