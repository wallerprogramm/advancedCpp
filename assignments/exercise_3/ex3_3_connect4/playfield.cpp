#include "playfield.h"
#include <iostream>

using namespace std;

playfield::playfield() {
    initialize();
}

playfield::~playfield() {

}

// return the stone (none/player1/player2) at the position(x,y)
// 0 <= x <= width
// 0 <= y <= height
// stoneat(0, 0)................top left
// stoneat(width-1, height-1) ...bottom right
// if we insert a stone in a new game in column i,
// it lands at (i,height-1)

// implementation may be changed, interface not
int playfield::stoneat(int x, int y) const {
    return rep[x][y];
}

// display the playfield
void playfield::display() {
    cout << endl;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cout << "| " << playersymbol[rep[x][y]];
        }
        cout << "|" << endl;
        cout << "----------------------" << endl;
    }
}

// insert a stone in x-th column
void playfield::drop(int player) {

    int choice;
    cout << "\nPlayer" << player << ", please select a number from 1 - 7: ";
    cin >> choice;

    //Error Checking

    if (cin.fail()) {
        cout << "Error!";
        exit(1);
    }

    while (choice > width || choice <= 0) {
        cout << "\nPlease select again: ";
        cin >> choice;
    }

    int number = 0;
    while (rep[(choice - 1)][(height - 1) - number] != none) {
        number++;
        if (number > (height - 1)) {
            cout << "\nPlease select again: ";
            cin >> choice;
            number = 0;  //You must reset the number else it will start at the beginning of the array
        }
    };

    rep[choice - 1][(height - 1) - number] = player;
    last_move_x = choice - 1;
    last_move_y = (height - 1) - number;
}

void playfield::drop_at(int x, int player) {
    int choice = x;
    cout << "\nPlayer" << player << ", please select a number from 1 - 7: ";

    // Probably not needed
    while (choice > width || choice <= 0) {
        cout << "\nPlease select again: ";
        cin >> choice;
    }

    int number = 0;
    while (rep[(choice - 1)][(height - 1) - number] != none) {
        number++;
        if (number > (height - 1)) {
            cout << "\nPlease select again: ";
            cin >> choice;
            number = 0;  //You must reset the number else it will start at the beginning of the array
        }
    };

    rep[choice - 1][(height - 1) - number] = player;
    last_move_x = choice - 1;
    last_move_y = (height - 1) - number;
}


// initialize game
void playfield::initialize() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            rep[x][y] = none;
        }
    }
}

// check diagonals used in check
bool playfield::check_diagonal_NW_SE(int x, int y, int player) {
    int score = 1;
    int count = 1;

    while ((x - count >= 0) && (y - count >= 0)) {
        if (rep[x - count][y - count] == player) { //Check direction NW
            score++;
            count++;
        } else break;  //If no combo is detected break from the loop
    }

    count = 1;
    while ((x + count < width) && (y + count < height)) {
        if (rep[x + count][y + count] == player) { //Check direction SE
            score++;
            count++;
        } else break;  //If no combo is detected break from the loop
    }

    if (score == 4) return true;
    else return false;
}

// check diagonals used in check
bool playfield::check_diagonal_NE_SW(int x, int y, int player) {
    int score = 1;
    int count = 1;

    while ((x + count < width) && (y - count >= 0)) {
        if (rep[x + count][y - count] == player) { //Check direction NE
            score++;
            count++;
        } else break;  //If no combo is detected break from the loop
    }

    count = 1;
    while ((x - count >= 0) && (y + count < height) ) {
        if (rep[x - count][y + count] == player) { //Check direction SW
            score++;
            count++;
        } else break;  //If no combo is detected break from the loop
    }

    if (score == 4) return true;
    else return false;
}

// check vertical used in check
bool playfield::check_vertical(int x, int y, int player) {
    // only down
    int score = 1;
    int count = 1;

    while ((y + count >= 0) && (y + count < height)) {
        if (rep[x][y + count] == player) { //Check South
            score++;
            count++;
        } else break;  //If no combo is detected break from the loop
    }

    if (score == 4) return true;
    else return false;
}

// check horizontal used in check
bool playfield::check_horizontal(int x, int y, int player) {
    int score = 1;
    int count = 1;
    // left
    while ((x + count >= 0) && (x + count < width)) {
        if (rep[x + count][y] == player) {  //Check East
            score++;
            count++;
        } else break;  //If no combo is detected break from the loop
    }
    // right
    count = 1;
    while ((x - count < height) && (x - count >= 0)) {
        if (rep[x - count][y] == player) { //Check West
            score++;
            count++;
        } else break;  //If no combo is detected break from the loop
    }

    if (score == 4) return true;
    else return false;
}

// check whether one has won with the stone inserted last
bool playfield::check_won(int x, int y, int player) {

    if (check_diagonal_NW_SE(x, y, player)) return true;
    else if (check_diagonal_NE_SW(x, y, player)) return true;
    else if (check_vertical(x, y, player)) return true;
    else if (check_horizontal(x, y, player)) return true;
    else return false;
}

int playfield::get_last_move_x() {
    return last_move_x;
}

int playfield::get_last_move_y() {
    return last_move_y;
}