#ifndef OBJEK_H
#define OBJEK_H
#include <iostream>
#include <string>

using namespace std;


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
        string front_side;
        string left, right;
        Node location = Node(2, -1, 3, -1, 1, false);
        int x, y;
    public:
        Robot(string hadap, string left, string kanan);
        ~Robot();
        void setRobot(string hadap, string left, string right);
        void BelokKanan(Robot &robot);
        void BelokKiri(Robot &robot);
        string getFront();
        string getLeft();
        string getRight();
        void setLoc(int x, int y);
        int getLocation();
        int getFrontNode();
        void setLocation(Node titik);
        bool getLineDoor();
};

//Implementasi method kelas Robot
Robot::Robot(string hadap, string left, string right){
    this->front_side = hadap;
    this->left = left;
    this->right = right;
}
//dtor
Robot::~Robot(){
}

void Robot::setLoc(int x, int y){
    this->x = x;
    this->y = y;
}

void Robot::setRobot(string hadap, string left, string right) {
    this->front_side = hadap;
    this->left = left;
    this->right = right;
}

string Robot::getFront() {
    return this->front_side;
}

string Robot::getLeft() {
    return this->left;
}

string Robot::getRight() {
    return this->right;
}

void Robot::BelokKanan(Robot &robot) {
    if (robot.getFront() == "south") {
        robot.setRobot("west", "south", "north");
    }
    else if (robot.getFront() == "west") {
        robot.setRobot("north", "west", "east");
    }
    else if (robot.getFront() == "north") {
        robot.setRobot("east", "north", "south");
    }
    else if (robot.getFront() == "east") {
        robot.setRobot("south", "east", "west");
    }
}

void Robot::BelokKiri(Robot &robot) {
    if (robot.getFront() == "south") {
        robot.setRobot("east", "north", "south");
    }
    else if (robot.getFront() == "west") {
        robot.setRobot("south", "east", "west");
    }
    else if (robot.getFront() == "north") {
        robot.setRobot("west", "south", "north");
    }
    else if (robot.getFront() == "east") {
        robot.setRobot("north", "west", "east");
    }
}

int Robot::getLocation(){
    return this->location.nama;
}

int Robot::getFrontNode(){
    int nodeDepan;
    if (this->front_side == "north"){
        nodeDepan = this->location.getNorth();
    } else if (this->front_side == "west"){
        nodeDepan = this->location.getWest();
    } else if (this->front_side == "south"){
        nodeDepan = this->location.getSouth();
    } else if (this->front_side == "east"){
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