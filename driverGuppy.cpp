#include <iostream>
#include "Guppy.hpp"
#include "Point.hpp"

using namespace std;

int main(){
    Point p1(5, 5);
    Guppy g1(p1);

    int ph = g1.getPhase();
    cout << "Phase : "<< ph << endl;
    g1.setPhase(2);
    cout << "Phase now :"<< ph << endl;
    g1.setFood_Count(4);
    g1.eat();
    int ph2 = g1.getPhase();
    cout << "Phase now :"<< ph2 << endl;
    
    return 0;
}