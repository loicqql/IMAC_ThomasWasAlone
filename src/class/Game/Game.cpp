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
        for(uint i = 0; i < actionAreas.size(); ++i) {
            Area * area = actionAreas[i];
            if(area->test(players[playerNum].getPos())) {
                switch (area->getAction()) {
                case STARTLEVEL1:
                        mode = PLAY;
                        blocks.clear();
                        loadPlay(true);
                    break;
                case STARTLEVEL2:
                        mode = PLAY;
                        blocks.clear();
                        loadPlay(false);
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

void Game::loadPlay(bool levelOne) {
    playerNum = 0;
    camera.clearAreas();
    images->setDelta(deltaCamera);
    actionAreas.clear();
    nbPlayers = 4;
    for (int i = 0; i < nbPlayers; i++) {
        players[i].setPos(new Vector((10.0 * i + 10.0 - deltaCamera->getX()) / deltaCamera->getZ(), (0.0 - deltaCamera->getY()) / deltaCamera->getZ()));
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

    if(levelOne) {

        setBlocksLevel1();

    }else {
        
        setBlocksLevel2();
    }
    
}

void Game::loadIntro() {
    for (int i = 0; i < nbPlayers; i++) {
        players[i].setPos(new Vector((10.0 * i + 10.0 - deltaCamera->getX()) / deltaCamera->getZ(), (0.0 - deltaCamera->getY()) / deltaCamera->getZ()));
    }
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

    for(uint i = nbPlayers; i < blocks.size(); ++i) {
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
    for(uint i = 0; i < actionAreas.size(); ++i) {
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


void Game::setBlocksLevel1() {
    win.setPlayer(&players[0], new Vector(110.0, 37.0));
    win.setPlayer(&players[1], new Vector(180.0, -35.0));
    win.setPlayer(&players[2], new Vector(235.0, 52.0));
    win.setPlayer(&players[3], new Vector(-20.0, 32.0));

    Box * box1 = new Box(357.0, 20.0, (121.0) - deltaCamera->getX(), (-60.0) - deltaCamera->getY());
    blocks.push_back(new Block(box1));

    Box * box2 = new Box(15.0, 200, (-50.0) - deltaCamera->getX(), (50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box2));

    Box * box3 = new Box(50, 50, (125.0) - deltaCamera->getX(), (-25.0) - deltaCamera->getY());
    blocks.push_back(new Block(box3));

    Box * box4 = new Box(15, 15, (75.0) - deltaCamera->getX(), (-43.0) - deltaCamera->getY());
    blocks.push_back(new Block(box4));
    
    Box * box5 = new Box(100, 10, (200.0) - deltaCamera->getX(), (-45.0) - deltaCamera->getY());
    blocks.push_back(new Block(box5));

    Box * box6 = new Box(75, 100, (260.0) - deltaCamera->getX(), (0.0) - deltaCamera->getY());
    blocks.push_back(new Block(box6));

    Box * box7 = new Box(35, 75, (-25.0) - deltaCamera->getX(), (-20.0) - deltaCamera->getY());
    blocks.push_back(new Block(box7));

    Box * box10 = new Box(15, 200, (292.5) - deltaCamera->getX(), (50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box10));

    Box * box11 = new Box(400, 15, (0.0) - deltaCamera->getX(), (175.0) - deltaCamera->getY());
    blocks.push_back(new Block(box11));

    map = new Map(1920, 1080);
    map->buildMap(blocks);

    Box * box8 = new Box(30, 5, (50.0) - deltaCamera->getX(), (5.0) - deltaCamera->getY());
    Block * block1 = new Block(box8);
    block1->setPosA(new Vector(50.0, 5.0));
    block1->setPosB(new Vector(130.0, 5.0));
    block1->setSteps(1000.0);
    blocks.push_back(block1);

    Box * box9 = new Box(30, 5, (110.0) - deltaCamera->getX(), (30.0) - deltaCamera->getY());
    Block * block2 = new Block(box9);
    block2->setPosA(new Vector(110.0, 30.0));
    block2->setPosB(new Vector(180.0, 30.0));
    block2->setSteps(1000.0);
    blocks.push_back(block2);
}

void Game::setBlocksLevel2() {
    for (int i = 0; i < nbPlayers; i++) {
        players[i].setPos(new Vector((10.0 * i - deltaCamera->getX()) / deltaCamera->getZ(), (0.0 - deltaCamera->getY()) / deltaCamera->getZ()));
    }
    win.setPlayer(&players[0], new Vector(110.0, -43.0));
    win.setPlayer(&players[1], new Vector(145.0, 22.0));
    win.setPlayer(&players[2], new Vector(15.0, -10.0));
    win.setPlayer(&players[3], new Vector(-20.0, 42.5));

    Box * box1 = new Box(357.0, 20.0, (121.0) - deltaCamera->getX(), (-60.0) - deltaCamera->getY());
    blocks.push_back(new Block(box1));
    Box * box2 = new Box(15.0, 200, (-50.0) - deltaCamera->getX(), (50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box2));
    Box * box3 = new Box(20, 28, (50.0) - deltaCamera->getX(), (-17.0) - deltaCamera->getY());
    blocks.push_back(new Block(box3));
    Box * box4 = new Box(110, 15, (0.0) - deltaCamera->getX(), (-45.0) - deltaCamera->getY());
    blocks.push_back(new Block(box4));
    Box * box5 = new Box(25, 5, (75.0) - deltaCamera->getX(), (-28.0) - deltaCamera->getY());
    blocks.push_back(new Block(box5));
    Box * box6 = new Box(25, 5, (150.0) - deltaCamera->getX(), (15.0) - deltaCamera->getY());
    blocks.push_back(new Block(box6));

    Box * box8 = new Box(50, 5, (-20.0) - deltaCamera->getX(), (22.0) - deltaCamera->getY());
    blocks.push_back(new Block(box8));
    Box * box9 = new Box(25, 5, (-20.0) - deltaCamera->getX(), (37.0) - deltaCamera->getY());
    blocks.push_back(new Block(box9));
    Box * box10 = new Box(34, 5, (-12.0) - deltaCamera->getX(), (50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box10));
    Box * box11 = new Box(5, 15, (-30.0) - deltaCamera->getX(), (45.0) - deltaCamera->getY());
    blocks.push_back(new Block(box11));
    Box * box12 = new Box(5, 30, (2.5) - deltaCamera->getX(), (37.0) - deltaCamera->getY());
    blocks.push_back(new Block(box12));

    Box * box13 = new Box(15.0, 200, (170.0) - deltaCamera->getX(), (50.0) - deltaCamera->getY());
    blocks.push_back(new Block(box13));

    Box * box14 = new Box(400, 15, (0.0) - deltaCamera->getX(), (100.0) - deltaCamera->getY());
    blocks.push_back(new Block(box14));

    map = new Map(1920, 1080);
    map->buildMap(blocks);

    Box * box7 = new Box(30, 5, (35.0) - deltaCamera->getX(), (30.0) - deltaCamera->getY());
    Block * block1 = new Block(box7);
    block1->setPosA(new Vector(35.0, 30.0));
    block1->setPosB(new Vector(110.0, 30.0));
    block1->setSteps(1000.0);
    blocks.push_back(block1);
}