#ifndef PLAYER_FACTORY_H_
#define PLAYER_FACTORY_H_

#include <list>

#include "player.h"

typedef player* makeType(const std::string &, int player_id);

class player_factory {
	static std::list<makeType*> make_funs;

public:
	static void add(makeType *m);
	static player *make(const std::string &plr, int player_id);

//	static player *make(const int *player_id);
};

template<class T>
struct player_factory_helper {
	player_factory_helper(makeType *m=(makeType*) &T::make) {
		player_factory::add(m);
	}
};


#endif // PLAYER_FACTORY_H_