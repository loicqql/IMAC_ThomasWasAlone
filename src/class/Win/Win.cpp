#include "Win.hpp"

using namespace std;

Win::Win() {}

void Win::setPlayer(Player * player, Vector * vectorPosWin) { 

    players.push_back(player);
    winPos.push_back(vectorPosWin);
}

void Win::clear() {
    if(players.empty()) {
        players.clear();
    }
    if(winPos.empty()) {
        winPos.clear();
    }
}

void Win::setDraw(Draw * udraw) {
    draw = udraw;
}

void Win::render() {
    for(uint i = 0; i < players.size(); ++i) {
        Player * player = players[i];
        Vector * pos = winPos[i];
        Vector * shape = player->getShape();
        draw->drawWin(new Area(shape->getX(), shape->getY(), pos->getX(), pos->getY(), 0.0), player->getColor());
        //show margin
        //draw->drawWin(new Area(shape->getX() + 10.0, shape->getY() + 10.0, pos->getX(), pos->getY(), 0.0), player->getColor());
    }
}

bool Win::testWin() {
    for(uint i = 0; i < players.size(); ++i) {
        Player * player = players[i];
        Vector * posWin = winPos[i];
        Vector * shape = player->getShape();
        Vector * posPlayer = player->getPos();
        float margin = 10.0;
        if(!((posPlayer->getX() > posWin->getX() - shape->getX() / 2 - margin) && (posPlayer->getX() < posWin->getX() + shape->getX() / 2 + margin))) {
            return false;
        }
        if(!((posPlayer->getY() > posWin->getY() - shape->getY() / 2 - margin) && (posPlayer->getY() < posWin->getY() + shape->getY() / 2 + margin))) {
            return false;
        }
    }
    return true;
}
