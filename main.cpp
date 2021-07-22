#include <iostream>
#include "arena.hpp"
#include "objek.hpp"

using namespace std;

int main (){
    int number;
    //char** arena;
    //arena = BuatPeta(20);
    //Node node1(5, 2, false, false, true, false, true, false);
    //Node node2(17, 7, false, false, true, false, true, false);
    //PrintPeta(arena, 20, node1);
    //PrintPeta(arena, 20, node2);
    //Bikin objek robot pake pointer

    Robot* robot = new Robot("south",  "east", "west"); //alokasi memori pointer
    // robot mulai dari node2
    cout << "Lokasi Awal : Node " << robot->getLocation() << endl;
    // Udah punya node depannya, tapi belum tau cara mindah location robotnya

    // Cek sisi-sisi robot
    // cout << robot->getFront() << endl;
    // cout << robot->getRight() << endl;
    // cout << robot->getLeft() << endl;
    // robot->BelokKanan(*robot);
    // robot->BelokKanan(*robot);
    // cout << robot->getFront() << endl;
    // cout << robot->getRight() << endl;
    // cout << robot->getLeft() << endl;


    // Main program
    Arena* arena = new Arena();
    arena->printArena();
    robot->BelokKanan();
    // cout << robot->getFrontNode() << endl;
    // Right wall following
    while(1){
        if (robot->getLineDoor()){
            cout << "Ketemu room 2" << endl;
            break;
        } else if (robot->getFrontNode() == -1){
            cout << "Belok kiri" << endl;
            robot->BelokKiri();
        } else {
            number = robot->getFrontNode();
            cout << "Pindah ke node " << number << endl;
            robotPindah(robot, number);
        }
    }

    // Left wall following
    // while(1){
    //     if (robot->getLineDoor()){
    //         cout << "Ketemu room" << endl;
    //         break;
    //     } else if (robot->getFrontNode() == -1){
    //         cout << "Belok kanan" << endl;
    //         robot->BelokKanan(*robot);
    //     } else {
    //         number = robot->getFrontNode();
    //         cout << "Pindah ke node " << number << endl;
    //         robotPindah(robot, number);
    //     }
    // }
    // explore room 1
    return 0;
}