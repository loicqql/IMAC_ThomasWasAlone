#include "Game.hpp"

using namespace std;

Game::Game() {
    mode = START;
    deltaCamera = camera.getDelta();
    win.setDraw(&draw);
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

void Game::switchPlayer() {
    if(mode == PLAY) {
        if(playerNum < 3) {
            ++playerNum;
        }else {
            playerNum = 0;
        }
    }
}

//Click
void Game::handleClick(Vector * vecClick) {
    if(mode == START || mode == PAUSE || mode == WIN) {
        if(gui.testAreas(vecClick)) {
            switchMode();
        }
    }    
}

//Press Enter
void Game::handleAction() {
    if(mode == INTRO) {
        for(int i = 0; i < actionAreas.size(); ++i) {
            Area * area = actionAreas[i];
            if(area->test(players[playerNum].getPos())) {
                switch (area->getAction()) {
                case STARTLEVEL1:
                        mode = PLAY;
                        blocks.clear();
                        loadPlay();
                    break;
                case STARTLEVEL2:
                        mode = PLAY;
                        blocks.clear();
                        loadPlay();
                    break;
                }
            }
        }
    }else {
        switchMode();
    }    
}

void Game::switchMode() {
    switch (mode) {
        case START:
            mode = INTRO;
            gui.clearArea();
            blocks.clear();
            loadIntro();
            break;
        case PAUSE:
            gui.clearArea();
            mode = PLAY;
            break;
        case WIN:
            mode = INTRO;
            gui.clearArea();
            blocks.clear();
            loadIntro();
            break;
        default:
            break;
    }
}

void Game::loadPlay() {
    playerNum = 0;
    camera.clearAreas();
    images->setDelta(deltaCamera);
    actionAreas.clear();
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

    players[1].setShape(new Vector(2.0, 9.0));
    players[2].setShape(new Vector(9.0, 2.0));
    players[3].setShape(new Vector(5.0, 5.0));

    win.setPlayer(&players[0], new Vector(-50.0, -40.0));
    win.setPlayer(&players[1], new Vector(-40.0, -41.0));
    win.setPlayer(&players[2], new Vector(-30.0, -48.0));
    win.setPlayer(&players[3], new Vector(-20.0, -45.0));

    
    Box * box1 = new Box(2000.0, 5.0, (0.0) - deltaCamera->getX(), (-50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box1));
	Box * box2 = new Box(30.0, 5.0, (-50.0) - deltaCamera->getX(), (-45.0) - deltaCamera->getY());

    Box * box3 = new Box(500.0, 5.0, (0.0) - deltaCamera->getX(), (60.0) - deltaCamera->getY());
    blocks.push_back(new Block(box3));

    Box * box4 = new Box(5.0, 140.0, (-100) - deltaCamera->getX(), (0) - deltaCamera->getY());
    blocks.push_back(new Block(box4));

    Box * box5 = new Box(5.0, 140.0, (100) - deltaCamera->getX(), (0) - deltaCamera->getY());
    blocks.push_back(new Block(box5));

    map = new Map(1920, 1080);
    map->buildMap(blocks);

    Block * aBlock = new Block(box2);
    aBlock->setPosA(new Vector(-50.0, -45.0));
    aBlock->setPosB(new Vector(50.0, 20.0));
    aBlock->setSteps(1000.0);
    blocks.push_back(aBlock);
    
}

void Game::loadIntro() {
    playerNum = 0;
    camera.clearAreas();
    camera.addAreas(new Area(50, 50, 0, -25, 0.7));
    images->setDelta(deltaCamera);
    nbPlayers = 1;
    players[0].setPos(new Vector(0.0, 0.0));
    players[0].setPlayerNumber(0);
    blocks.push_back(new Block(players[0].getBox()));

    Area * area1 = new Area(75.0, 100.0, -75.0, -47.5, 0.0);
    Area * area2 = new Area(75.0, 100.0, 75.0, -47.5, 0.0);
    area1->setAction(STARTLEVEL1);
    area2->setAction(STARTLEVEL2);
    actionAreas.push_back(area1);
    actionAreas.push_back(area2);
    
    players[0].setColor(new Color(1.0, 1.0, 1.0));

    Box * box1 = new Box(300, 5.0, (0.0) - deltaCamera->getX(), (-50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box1));

    Box * box2 = new Box(300, 5.0, (0.0) - deltaCamera->getX(), (150.0) - deltaCamera->getY());
    blocks.push_back(new Block(box2));

    Box * box3 = new Box(5.0, 205.0, (147.5) - deltaCamera->getX(), (50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box3));

    Box * box4 = new Box(5.0, 205.0, (-147.5) - deltaCamera->getX(), (50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box4));

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
        case WIN:
            renderWin();
            break;
        default:
            break;
    }
}

void Game::renderPlay() {

    ray.setBlocks(blocks);
    ray.render();

    blocksNearPlayer = map->search(players[playerNum].getPos());

    for (int i = 0; i < nbPlayers; i++) {
        players[i].setBlocks(blocksNearPlayer);
    }

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

    win.render();

    if(win.testWin()) {
        gui.setUpAreasWin();
        mode = WIN;
    }

    //debug zoom
    camera.showArea();

}

void Game::renderIntro() {

    ray.setBlocks(blocks);
    ray.render();
    for(int i = 0; i < actionAreas.size(); ++i) {
        draw.drawDoor(actionAreas[i]);
    }
    
    players[0].render();
    players[0].drawTriangle();
    draw.render(blocks, nbPlayers);

    images->render(4, new Vector(25.4 * 2, 15.0 * 2), new Vector(-100.0, 0.0), true);
    images->render(5, new Vector(25.4 * 2, 15.0 * 2), new Vector(100.0 - 25.4 * 2, 0.0), true);
    images->render(6, new Vector(29.1 * 2, 25.0 * 2), new Vector(-29.1, -25.0), true);

    //debug zoom
    //camera.showArea();
}

void Game::renderStart() {
    images->render(2, new Vector(382.2 * 2, 300.0 * 2), new Vector(-502.2, -300.0), false);
    images->render(0, new Vector(78.0 * 2, 50.0 * 2), new Vector(-78.0, -50.0), false);

    //debug menu
    // gui.showArea();

}

void Game::renderPause() {
    images->render(2, new Vector(382.2 * 2, 300.0 * 2), new Vector(-382.2, -300.0), false);
    images->render(1, new Vector(93.0 * 2, 30.0 * 2), new Vector(-93.0, -30.0), false);


    //debug menu
    // gui.showArea();

}

void Game::renderWin() {
    images->render(2, new Vector(382.2 * 2, 300.0 * 2), new Vector(-202.2, -300.0), false);
    images->render(3, new Vector(78.0 * 2, 50.0 * 2), new Vector(-78.0, -50.0), false);

    // gui.showArea();
}

void Game::pauseGame() {
    if(mode == PLAY) {
        gui.setUpAreasPause();
        mode = PAUSE;
    }else if (mode == PAUSE) {
        gui.clearArea();
        mode = PLAY;
    }
    
    players[0].render();
    players[0].drawTriangle();
    draw.render(blocks, nbPlayers);

    images->render(4, new Vector(25.4 * 2, 15.0 * 2), new Vector(-100.0, 0.0), true);
    images->render(5, new Vector(25.4 * 2, 15.0 * 2), new Vector(100.0 - 25.4 * 2, 0.0), true);
    images->render(6, new Vector(29.1 * 2, 25.0 * 2), new Vector(-29.1, -25.0), true);

    //debug zoom
    //camera.showArea();
}

void Game::setImage(Image * yimages) {
    images = yimages;
}
