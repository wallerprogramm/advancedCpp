#ifndef DOMINIK_PLAYFIELD_H_
#define DOMINIK_PLAYFIELD_H_

#include <vector>

#include "playfield.h"

class
dominik_playfield : public playfield {
    bool check_diagonal_NW_SE(int x, int y, int player);
    bool check_diagonal_NE_SW(int x, int y, int player);
    bool check_vertical(int x, int y, int player);
    bool check_horizontal(int x, int y, int player);
    const char playersymbol[3] = {' ', 'X', 'O'};
//public:
//// the size of the field
//    const static int width = 7;
//    const static int height = 6;
//// these elements are used to indicate whether a given position
//// in the playing field is taken by a given player
//    const static int none = 0;
//    const static int player1 = 1;
//    const static int player2 = 2;
protected:
// the internal representation of the field
    char rep[playfield::width][playfield::height];
    int last_move_x;
    int last_move_y;
public:
    dominik_playfield();

    ~dominik_playfield();
// return the stone (none/player1/player2) at the position(x,y)
// 0 <= x <= width
// 0 <= y <= height
// stoneat(0, 0)................top left
// stoneat(width-1, height-1) ...bottom right
// if we insert a stone in a new game in column i,
// it lands at (i,height-1)

// implementation may be changed, interface not
    int stoneat(int x, int y) const;
// display the playfield
    void display();
// insert a stone in x-th column
    void drop(int player);
    void drop_at(int x, int player);
// initialize game
    void initialize();
    // check whether one has won with the stone inserted last
    bool check_won(int x, int y, int player);

    int get_last_move_x();
    int get_last_move_y();

};

#endif // DOMINIK_PLAYFIELD_H_
