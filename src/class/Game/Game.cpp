#include "Game.hpp"

using namespace std;

Game::Game() {
    playerNum = 0;
    players[0].setColor(new Color(1.0, 0.0, 0.0));
    players[1].setColor(new Color(0.0, 1.0, 0.0));
    players[2].setColor(new Color(0.0, 0.0, 1.0));
    players[3].setColor(new Color(0.5, 0.5, 0.5));
}

void Game::movePlayer(Vector * vecInput) {
    players[playerNum].move(vecInput);
    Vector * vec = players[playerNum].getPos();
    deltaCamera = camera.playerMove(vec);
    players[playerNum].setDelta(deltaCamera);
}

void Game::render() {
    players[0].render();
    players[1].render();
    players[2].render();
    players[3].render();

    players[playerNum].drawTriangle();
}

void Game::switchPlayer() {
    if(playerNum < 3) {
        ++playerNum;
    }else {
        playerNum = 0;
    }
}

