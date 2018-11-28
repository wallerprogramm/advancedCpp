#ifndef INTERACTIVE_PLAYER_H_
#define INTERACTIVE_PLAYER_H_

#include <iostream>
#include "playfield.h"
#include "player.h"

class interactive_player : public player {
	const int player_id;

public:
	interactive_player(int player_id);

	virtual ~interactive_player();

	virtual int play(const playfield &field);
};


#endif // INTERACTIVE_PLAYER_H_