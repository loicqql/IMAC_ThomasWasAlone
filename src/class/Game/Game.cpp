#include "Game.hpp"

#include "../Map/Map.hpp"

#include <iostream>

using namespace std;

Game::Game() {
    deltaCamera = camera.getDelta();
    playerNum = 0;
    for (int i = 0; i < 4; i++) {
        players[i].setPos(new Vector(10.0 * i, 0.0));
        players[i].setPlayerNumber(i);
        blocks.push_back(new Block(players[i].getBox()));
    }
    
    players[0].setColor(new Color(1.0, 0.0, 0.0));
    players[1].setColor(new Color(0.0, 1.0, 0.0));
    players[2].setColor(new Color(0.0, 0.0, 1.0));
    players[3].setColor(new Color(0.5, 0.5, 0.5));

    //TEMP get from map
    /*
    Box * box1 = new Box(2000.0, 5.0, (0.0) - deltaCamera->getX(), (-50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box1));
	Box * box2 = new Box(30.0, 5.0, (-50.0) - deltaCamera->getX(), (-45.0) - deltaCamera->getY());

    Block * aBlock = new Block(box2);
    aBlock->setPosA(new Vector(-50.0, -45.0));
    aBlock->setPosB(new Vector(50.0, 20.0));
    aBlock->setSteps(1000.0);
    blocks.push_back(aBlock);
    */

    Block * a = new Block(new Box(10.0, 10.0, (0.0) - deltaCamera->getX(), (10.0) - deltaCamera->getY()));
    Block * b = new Block(new Box(10.0, 10.0, (1100.0) - deltaCamera->getX(), (800.0) - deltaCamera->getY()));
    Block * c = new Block(new Box(10, 10.0, (1100.0) - deltaCamera->getX(), (10.0) - deltaCamera->getY()));
    Block * d = new Block(new Box(10.0, 10.0, (30.0) - deltaCamera->getX(), (800.0) - deltaCamera->getY()));
    Block * e = new Block(new Box(10.0, 10.0, (50.0) - deltaCamera->getX(), (10.0) - deltaCamera->getY()));
    //Block f = Block(new Box(75, 60.0, (30.0) - deltaCamera->getX(), (45.0) - deltaCamera->getY()));
    
    vector<Block*> allBlocks;
    allBlocks.push_back(a);
    allBlocks.push_back(b);
    allBlocks.push_back(c);
    allBlocks.push_back(d);
    allBlocks.push_back(e);
    //allBlocks.push_back(f);

    map = new Map(1920, 1080);
    map->buildMap(allBlocks);

    //set Delta to everyone
    draw.setDelta(deltaCamera);
    for (int i = 0; i < 4; i++) {
        players[i].setDelta(deltaCamera);
    }

}

void Game::movePlayer(Vector * vecInput) {
    for (int i = 0; i < 4; i++) {
        players[i].setBlocks(blocks);
        if(i != playerNum) {
            players[i].move(new Vector(0.0, 0.0));
        }
    }
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

    for(uint i = 4; i < blocks.size(); ++i) {
        Block * block = blocks[i];
        block->updateMovement();
    }

    //vector<Block *> bLeaves = map->getLeaves(map->getRoot());

    draw.render(blocks);
    //map->drawMap();

    //debug zoom
    camera.showArea();

}

void Game::switchPlayer() {
    if(playerNum < 3) {
        ++playerNum;
    }else {
        playerNum = 0;
    }
}

