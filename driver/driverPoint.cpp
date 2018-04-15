#include <iostream>
#include "../src/Point.hpp"

using namespace std;

int main(){
    double dist;
    int X, Y;

    Point p1(0, 0);
    Point p2(3, 4);
    Point p3(0, 0);

    dist = p1.distanceTo(p2);
    p3 = p1 + p2;
    X = p3.getX();
    Y = p3.getY(); 

    cout << dist << endl;
    cout << X << ", " << Y << endl;
}