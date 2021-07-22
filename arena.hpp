#ifndef ARENA_H
#define ARENA_H
#include "objek.hpp"

class Arena{
    public:
    Arena();
    Arena(int x, int y);
    ~Arena();
    void printArena();
    //void exploremaze();

    private:
    //Robot robot;
    int x;
    int y;
};

Arena::Arena(){}

Arena::Arena(int x, int y){
    this->x = x;
    this->y = y;
}

Arena::~Arena(){}

void Arena::printArena(){
    cout << "Arena KRSRI" << endl; 
    cout << "__________________________________"<< endl;
    cout << "|  1           2               3  |" << endl;
    cout << "|     _______________________     |" << endl;
    cout << "|     |                     |     |" << endl;
    cout << "| 15  |         9           |     |" << endl;
    cout << "|     |______      ______   |     |" << endl;
    cout << "|                        \\  |  4  |" << endl;
    cout << "| 11    10      8         \\_|     |" << endl;
    cout << "|      __________      7    |     |" << endl;
    cout << "|     |          \\          |     |" << endl;
    cout << "| 12  |           \\               |" << endl;
    cout << "|                  \\              |" << endl;
    cout << "| 13       14       |  6       5  |" << endl;
    cout << "|___________________|_____________|" << endl;
}

// Buat objek node
Node node1(1, -1, 2, 15, -1, false);
Node node2(2, -1, 3, -1, 1, false);
Node node3(3, -1, -1, 4, 2, false);
Node node4(4, 3, -1, 5, -1, false);
Node node5(5, 4, -1, -1, 6, false);
Node node6(6, 7, 5, -1, -1, false);
Node node7(7, -1, -1, 6, 8, false);
Node node8(8, 9, 7, -1, 10, true);
Node node9(9, -1, -1, -1, 8, false);
Node node10(10, -1, 8, -1, 11, false);
Node node11(11, 15, 10, 12, -1, false);
Node node12(12, 11, -1, 13, -1, false);
Node node13(13, 12, 14, -1, -1, true);
Node node14(14, -1, -1, -1, 13, false);
Node node15(15, 1, -1, 11, -1, false);

/**
 * @param robot Objek robot yang udah diconstruct
 * @param number Nomor node yang akan dituju
 */
void robotPindah(Robot* robot, int number);

void robotPindah(Robot* robot, int number){
    switch (number){
        case 1:
            robot->setLocation(node1);
            break;
        case 2:
            robot->setLocation(node2);
            break;
        case 3:
            robot->setLocation(node3);
            break;
        case 4:
            robot->setLocation(node4);
            break;
        case 5:
            robot->setLocation(node5);
            break;
        case 6:
            robot->setLocation(node6);
            break;
        case 7:
            robot->setLocation(node7);
            break;
        case 8:
            robot->setLocation(node8);
            break;
        case 9:
            robot->setLocation(node9);
            break;
        case 10:
            robot->setLocation(node10);
            break;
        case 11:
            robot->setLocation(node11);
            break;
        case 12:
            robot->setLocation(node12);
            break;
        case 13:
            robot->setLocation(node13);
            break;
        case 14:
            robot->setLocation(node14);
            break;
        case 15:
            robot->setLocation(node15);
            break;
        
        default:
            break;
    }
}

#endif