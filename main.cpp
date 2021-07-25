#include <iostream>
#include "arena.hpp"
#include "objek.hpp"
#inc

using namespace std;

int main (){
    int number;
    Robot* robot = new Robot(south); //alokasi memori pointer
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
    // 2 -> 1 -> 15 -> 11 -> 12 -> 13 -> 14 (explore room 2)
    // 14 -> 13 -> 12 -> 11 -> 10 -> 8 -> 9 (explore room 1)
    // 9 -> 8 -> 10 -> 11 -> 15 -> 1 -> 2 (selesai)
    Arena* arena = new Arena();
    arena->printArena();
    robot->BelokKanan();
    // cout << robot->getFrontNode() << endl;
    // Right wall following
    while(1){
        if (robot->getLineDoor()){
            cout << "Robot menemukan room 2" << endl;
            break;
        } else if (robot->getFrontNode() == -1){
            robot->BelokKiri();
        } else {
            number = robot->getFrontNode();
            robotPindah(robot, number);
        }
    }
    
    // Explore room 2
    robot->BelokKiri();
    cout << "Masuk ke room 2" << endl;
    robotPindah(robot, 14);
    PathtoRoom2();
    cout << "Explore Room 2" << endl;
    cout << "Robot berhasil menyelamatkan korban dan memadamkan api" << endl;
    sleep(3);
    cout << "Selesai explore room 2" << endl;
    robot->BelokKiri();
    robot->BelokKiri();
    cout << "Keluar dari room 2" << endl;
    robotPindah(robot, 13);
    robot->BelokKanan();
    robotPindah(robot, 12);

    // Right wall following
    while(1){
        if (robot->getLocation() == 11){
            robot->BelokKanan();
            robotPindah(robot, 10);
        } else if (robot->getLocation() == 8){
            cout << "Ketemu room 1" << endl;
            break;
        } else {
            number = robot->getFrontNode();
            robotPindah(robot, number);
        }
    }
    // explore room 1
    robot->BelokKiri();
    cout << "Masuk ke room 1" << endl;
    robotPindah(robot, 9);
    PathtoRoom1();
    cout << "Explore Room 1" << endl;
    cout << "Robot berhasil menyelamatkan korban dan memadamkan api" << endl;
    sleep(3);
    cout << "Selesai explore room 1" << endl;
    robot->BelokKiri();
    robot->BelokKiri();
    cout << "Keluar dari room 1" << endl;
    robotPindah(robot, 8);
    robot->BelokKanan();
    robotPindah(robot, 10);

    // Balik ke HOME
    // Right wall following
    while(1){
        if (robot->getLocation() == 2){
            cout << "Yeee dah balik rumah" << endl;
            break;
        } else if (robot->getFrontNode() == -1){
            robot->BelokKanan();
        } else {
            number = robot->getFrontNode();
            robotPindah(robot, number);
        }
    }
    PathtoHome();
    return 0;
}
