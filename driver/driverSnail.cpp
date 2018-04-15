#include <iostream>
#include "../src/Snail.hpp"
#include "../src/Point.hpp"

using namespace std;

int main(){
    Point p1(5, 5);
    Snail s1(p1);

    int speed = s1.getSpeed();
    cout << "Snail terbentuk dengan kecepatan :"<< speed << endl;
    
    return 0;
}