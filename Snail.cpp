#include <iostream>
#include "Summonable.hpp"
#include "Snail.hpp"
#include "Matrix.hpp"

using namespace std;

static const int speed_snail = 10;

/*Sekawan*/
Snail::Snail(Point p) : Summonable("snail", speed_snail, p){ 
}

/*Getter*/
static int getSpeed_Snail(){
    return speed_snail;
}

/*Setter*/

/*Method*/
void move(){
    //untuk pergerakan snail
}
void show(); //untuk display snail

