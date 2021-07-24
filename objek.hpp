#ifndef OBJEK_H
#define OBJEK_H
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

typedef enum{
    south,
    west,
    north,
    east
} dir;

//Class Node
//Kurang fungsi mendeteksi node di sekitar
class Node {
    private:
        // int x, y;
        int east, west, north, south;
        bool lineDoor;
    public:
        int nama;
        Node(int nama, int north, int east, int south, int west, bool lineDoor);
        ~Node();
        void setNode(int nama, int north, int east, int south, int west, bool lineDoor);
        // int getX();
        // int getY();
        int getNorth();
        int getWest();
        int getSouth();
        int getEast();
        bool isLineDoor();
};

//Implementasi methode kelas Node
Node::Node(int nama, int north, int east, int south, int west, bool lineDoor){
    this->nama = nama;
    this->north = north;
    this->east = east;
    this->south = south;
    this->west = west;
    this->lineDoor = lineDoor;
}

Node::~Node(){
}

void Node::setNode(int nama, int north, int east, int south, int west, bool lineDoor) {
    this->nama = nama;
    this->north = north;
    this->east = east;
    this->south = south;
    this->west = west;
    this->lineDoor = lineDoor;
}

int Node::getNorth(){
    return this->north;
}

int Node::getWest(){
    return this->west;
}

int Node::getSouth(){
    return this->south;
}

int Node::getEast(){
    return this->east;
}

bool Node::isLineDoor(){
    return this->lineDoor;
}

// int Node::getX() {
//     return this->x;
// }

// int Node::getY() {
//     return this->y;
// }

//Class robot
class Robot {
    private:
        int front_side;
        int left, right;
        Node location = Node(2, -1, 3, -1, 1, false);
        int x, y;
    public:
        Robot(dir hadap);
        ~Robot();
        void setRobot(dir hadap);
        void BelokKanan();
        void BelokKiri();
        int getFront();
        int getLeft();
        int getRight();
        void setLoc(int x, int y);
        int getLocation();
        int getFrontNode();
        void setLocation(Node titik);
        bool getLineDoor();
};

//Implementasi method kelas Robot
Robot::Robot(dir hadap){
    this->front_side = hadap;
    this->left = (hadap+3)%4;
    this->right = hadap+1;
}
//dtor
Robot::~Robot(){
}

void Robot::setLoc(int x, int y){
    this->x = x;
    this->y = y;
}

void Robot::setRobot(dir hadap) {
    this->front_side = hadap;
    this->left = (hadap+3)%4;
    this->right = hadap+1;
}

int Robot::getFront() {
    return this->front_side;
}

int Robot::getLeft() {
    return this->left;
}

int Robot::getRight() {
    return this->right;
}

void Robot::BelokKanan() {
    sleep(1);
    cout << "Belok kanan" << endl;
    this->setRobot((dir)(this->getRight()));
}

void Robot::BelokKiri() {
    sleep(1);
    cout << "Belok kiri" << endl;
    this->setRobot((dir)(this->getLeft()));
}

int Robot::getLocation(){
    return this->location.nama;
}

int Robot::getFrontNode(){
    int nodeDepan;
    if ((dir)this->front_side == north){
        nodeDepan = this->location.getNorth();
    } else if ((dir)this->front_side == west){
        nodeDepan = this->location.getWest();
    } else if ((dir)this->front_side == south){
        nodeDepan = this->location.getSouth();
    } else if ((dir)this->front_side == east){
        nodeDepan = this->location.getEast();
    }
    
    return nodeDepan;
}

void Robot::setLocation(Node titik){
    this->location = titik;
}

bool Robot::getLineDoor(){
    bool lineDoor = this->location.isLineDoor();
    return lineDoor;
}

#endif