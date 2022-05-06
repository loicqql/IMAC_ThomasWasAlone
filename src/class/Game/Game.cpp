#include "Game.hpp"

using namespace std;

Game::Game() {
    deltaCamera = camera.getDelta();
    playerNum = 0;
    for (int i = 0; i < 4; i++) {
        players[i].setPos(new Vector(10.0 * i, 0.0));
        players[i].setPlayerNumber(i);
        boxs.push_back(players[i].getBox());
    }
    
    players[0].setColor(new Color(1.0, 0.0, 0.0));
    players[1].setColor(new Color(0.0, 1.0, 0.0));
    players[2].setColor(new Color(0.0, 0.0, 1.0));
    players[3].setColor(new Color(0.5, 0.5, 0.5));

    //TEMP update from map
    Box * box1 = new Box(2000.0, 5.0, 0.0 - deltaCamera->getX(), (-50.0) - deltaCamera->getY());
	Box * box2 = new Box(50.0, 50.0, (-30.0) - deltaCamera->getX(), (-20.0) - deltaCamera->getY());
	boxs.push_back(box1);
    boxs.push_back(box2);

    //set Delta to everyone
    draw.setDelta(deltaCamera);
    for (int i = 0; i < 4; i++) {
        players[i].setDelta(deltaCamera);
    }

}

void Game::movePlayer(Vector * vecInput) {
    players[playerNum].setBoxs(boxs);
    players[playerNum].move(vecInput);
    Vector * vec = players[playerNum].getPos();
    deltaCamera = camera.playerMove(vec);
}

void Game::render() {
    players[0].render();
    players[1].render();
    players[2].render();
    players[3].render();

    players[playerNum].drawTriangle();

    draw.render(boxs);

}

void Game::switchPlayer() {
    if(playerNum < 3) {
        ++playerNum;
    }else {
        playerNum = 0;
    }
}

