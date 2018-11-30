#include <list>

#include "player_factory.h"

std::list<makeType*> player_factory::make_funs;

void player_factory::add(makeType *m) {
	make_funs.push_back(m);
}

player *player_factory::make(const std::string &plr, int player_id) {
	for (makeType *make_fun : make_funs) {
		player *new_player = make_fun(plr, player_id);
		if (new_player) return new_player;
	}
	return nullptr;
}