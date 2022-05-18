#include "Map.hpp"

using namespace std;

Map::Map(float width, float height, Elt * root){
    w = width;
    h = height;

    r = root;
}

float Map::getHeight(){
    return h;
}

float Map::getWidth(){
    return w;
}

void Map::buildMap(vector<Block> b){

    for(Block i : b){
        r->insert(i);
    }

}

vector<Elt> Map::getLeaves(Elt node){
    vector<Elt> leaves;
    if(node.isLeaf()){
        leaves.push_back(node);
    }
    if(!node.isLeaf()){
        getLeaves(node.getChildA());
        getLeaves(node.getChildB());
        getLeaves(node.getChildC());
        getLeaves(node.getChildD());
    }

    return leaves;
}

void Map::draw(){
    vector<Elt> leaves = getLeaves();
    glBegin(GL_POLYGON);
    glLoadIdentity();
    foreach($leaves as $element){
        glColor3f(0.5);
        //ajouter conversion des coords
        glVertex2f($element.getOrigin()->getX());
        glVertex2f($element.getOrigin()->getY());
        glVertex2f($element.getWidth());
        glVertex2f($element.getHeight());
    }
    glEnd();
}