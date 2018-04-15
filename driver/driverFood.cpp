#include "../src/Food.hpp"
#include <iostream>
using namespace std;

int main() {
    Point P1(150, 100);
    Food C1(P1);

    Matrix M;

    cout << "Direction : " << C1.getDirection() << endl;
    cout << "Position : " << C1.getPosition() << endl;
    cout << "Speed : " << C1.getSpeed() << endl;
    cout << "Radius : " << C1.getRadius_Food() << endl;
    cout << "Image : " << C1.getImage() << endl;
    cout << "Harga : " << C1.getValue_Food() << endl;

    Food C2(P1);
    cout << "Operator== : " << (C2 == C1) << endl;
    
    int time = 0;

    while (time < 3) {
        time++;
        C1.move(M, time);
        cout << "---- SETELAH MOVE " << time << " SEC ----" << endl;
        cout << "Direction : " << C1.getDirection() << endl;
        cout << "Position : " << C1.getPosition() << endl;
        cout << "Speed : " << C1.getSpeed() << endl;
        cout << "Radius : " << C1.getRadius_Food() << endl;
        cout << "Image : " << C1.getImage() << endl;
    }

    return 0;
}