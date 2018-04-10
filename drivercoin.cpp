#include "Coin.hpp"
#include <iostream>

using namespace std;

int main() {
    Point P1(150, 400);
    Coin C1(P1, 10);

    Matrix M;

    cout << "Direction : " << C1.getDirection() << endl;
    cout << "Position : " << C1.getPosition() << endl;
    cout << "Speed : " << C1.getSpeed() << endl;
    cout << "Radius : " << C1.getRadius_Coin() << endl;
    cout << "Image : " << C1.getImage() << endl;

    Coin C2(P1, 10);
    cout << "Operator== : " << (C2 == C1) << endl;
    
    C1.move(M, 1);
    cout << "---- SETELAH MOVE 1 SEC ----" << endl;
    cout << "Direction : " << C1.getDirection() << endl;
    cout << "Position : " << C1.getPosition() << endl;
    cout << "Speed : " << C1.getSpeed() << endl;
    cout << "Radius : " << C1.getRadius_Coin() << endl;
    cout << "Image : " << C1.getImage() << endl;

    C1.move(M, 2);
    cout << "---- SETELAH MOVE 2 SEC ----" << endl;
    cout << "Direction : " << C1.getDirection() << endl;
    cout << "Position : " << C1.getPosition() << endl;
    cout << "Speed : " << C1.getSpeed() << endl;
    cout << "Radius : " << C1.getRadius_Coin() << endl;
    cout << "Image : " << C1.getImage() << endl;

    return 0;
}