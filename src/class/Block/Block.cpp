#include "Block.hpp"

using namespace std;

Block::Block(Box * aBox) {
    box = aBox;
}

Box * Block::getBox() {
    return box;
}
