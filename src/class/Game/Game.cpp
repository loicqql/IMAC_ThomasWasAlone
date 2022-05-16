#include "Game.hpp"

using namespace std;

Game::Game() {
    mode = START;
    deltaCamera = camera.getDelta();
    playerNum = 0;
    nbPlayers = 4;

    //set Delta to everyone
    draw.setDelta(deltaCamera);
    for (int i = 0; i < nbPlayers; i++) {
        players[i].setDelta(deltaCamera);
    }

    ray.setBlocks(blocks);
    ray.setDelta(deltaCamera);

}

void Game::movePlayer(Vector * vecInput) {
    if(mode == PLAY || mode == INTRO) {
        for (int i = 0; i < nbPlayers; i++) {
            players[i].setBlocks(blocks);
            if(i != playerNum) {
                players[i].move(new Vector(0.0, 0.0));
            }
        }
        players[playerNum].move(vecInput);
        Vector * vec = players[playerNum].getPos();
        deltaCamera = camera.playerMove(vec);
    }
}

void Game::handleClick(Vector * vecClick) {
    if(mode == START || mode == PAUSE) {
        if(gui.testAreas(vecClick)) {
            switch (mode) {
                case START:
                    mode = INTRO;
                    blocks.clear();
                    loadIntro();
                    break;
                case PAUSE:
                    mode = PLAY;
                    break;
                default:
                    break;
            }
        }
    }    
}

void Game::loadPlay() {
    nbPlayers = 4;
    for (int i = 0; i < nbPlayers; i++) {
        players[i].setPos(new Vector(10.0 * i, 0.0));
        players[i].setPlayerNumber(i);
        blocks.push_back(new Block(players[i].getBox()));
    }
    
    players[0].setColor(new Color(1.0, 0.0, 0.0));
    players[1].setColor(new Color(0.0, 1.0, 0.0));
    players[2].setColor(new Color(0.0, 0.0, 1.0));
    players[3].setColor(new Color(0.5, 0.5, 0.5));

    //TEMP get from map
    Box * box1 = new Box(2000.0, 5.0, (0.0) - deltaCamera->getX(), (-50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box1));
	Box * box2 = new Box(30.0, 5.0, (-50.0) - deltaCamera->getX(), (-45.0) - deltaCamera->getY());

    Block * aBlock = new Block(box2);
    aBlock->setPosA(new Vector(-50.0, -45.0));
    aBlock->setPosB(new Vector(50.0, 20.0));
    aBlock->setSteps(1000.0);
    blocks.push_back(aBlock);

    Box * box3 = new Box(500.0, 5.0, (0.0) - deltaCamera->getX(), (60.0) - deltaCamera->getY());
    blocks.push_back(new Block(box3));

    Box * box4 = new Box(5.0, 140.0, (-100) - deltaCamera->getX(), (0) - deltaCamera->getY());
    blocks.push_back(new Block(box4));

    Box * box5 = new Box(5.0, 140.0, (100) - deltaCamera->getX(), (0) - deltaCamera->getY());
    blocks.push_back(new Block(box5));
}

void Game::loadIntro() {
    nbPlayers = 1;
    players[0].setPos(new Vector(0.0, 0.0));
    players[0].setPlayerNumber(0);
    blocks.push_back(new Block(players[0].getBox()));
    
    players[0].setColor(new Color(1.0, 0.0, 0.0));

    //TEMP get from map
    Box * box1 = new Box(150, 5.0, (0.0) - deltaCamera->getX(), (-50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box1));

    Box * box2 = new Box(150, 5.0, (0.0) - deltaCamera->getX(), (50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box2));


}

void Game::pauseGame() {
    if(mode == PLAY) {
        gui.setUpAreasPause();
        mode = PAUSE;
    }    
}

void Game::renderPlay() {

    ray.setBlocks(blocks);
    ray.render();

    players[0].render();
    players[1].render();
    players[2].render();
    players[3].render();

    players[playerNum].drawTriangle();

    for(int i = nbPlayers; i < blocks.size(); ++i) {
        Block * block = blocks[i];
        block->updateMovement();
    }

    draw.render(blocks, nbPlayers);

    //debug zoom
    camera.showArea();

}

void Game::renderIntro() {
    ray.setBlocks(blocks);
    ray.render();
    players[0].render();
    players[0].drawTriangle();
    draw.render(blocks, nbPlayers);
}

void Game::renderStart() {

    gui.showStart();

    //debug menu
    gui.showArea();

}

void Game::renderPause() {

    
    gui.showStart();

    //debug menu
    gui.showArea();

}

void Game::render() {
    switch (mode) {
        case START:
            renderStart();
            break;
        case INTRO:
            renderIntro();
            break;
        case PAUSE:
            renderPause();
            break;
        case PLAY:
            renderPlay();
            break;
        default:
            break;
    }
}

void Game::switchPlayer() {
    if(mode == PLAY) {
        if(playerNum < 3) {
            ++playerNum;
        }else {
            playerNum = 0;
        }
    }
}

