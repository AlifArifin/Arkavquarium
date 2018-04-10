#include <iostream>
#include "Piranha.hpp"
#include "Point.hpp"

using namespace std;

int main(){
    Point p1(5, 5);
    Piranha pr(p1);

    int ph = g1.getValue_Piranha();
    cout << "Piranha seharga : "<< ph << "Telah di-construct. "<< endl;
    
    return 0;
}