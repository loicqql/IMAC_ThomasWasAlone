#pragma once

#include <vector>

#include "../Player/Player.hpp"
#include "../utils/Vector/Vector.hpp"
#include "../utils/Area/Area.hpp"
#include "../utils/Draw/Draw.hpp"

using namespace std;

class Win {
	public:
		Win();
        void setPlayer(Player * player, Vector * vectorPosWin);
        void clear();
        void render();
        void setDraw(Draw * udraw);
        bool testWin();
		
	private:
		vector <Player*> players;
        vector <Vector *> winPos;
        Draw * draw;
};