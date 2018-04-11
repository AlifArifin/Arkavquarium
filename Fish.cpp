#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Fish.hpp"
#include "Summonable.hpp"

using namespace std;

const int Fish::hunger_time = 6;
const int Fish::dead_time = 12;
const int Fish::speed_fish = 40;

Fish::Fish(int _v, Point _p) : Summonable(speed_fish, _p), value(_v) {
    hungry = false;
    count_move = 0;
    setChange_Move();
}

Fish::~Fish() {

}

/*Getter*/
bool Fish::getHungry() const {
    return hungry;
}


int Fish::getHunger_Time() {
    return hunger_time;
}

int Fish::getDead_Time() {
    return dead_time;
} 

double Fish::getCount_Move() const {
    return count_move;
}

double Fish::getChange_Move() const {
    return change_move;
}

int Fish::getSpeed_Fish() {
    return speed_fish;
}

/*Setter*/
void Fish::setHungry(bool _h) {
    hungry = _h;
}


void Fish::setCount_Move(double _c) {
    count_move = _c;
}

void Fish::setChange_Move() {
    change_move = (rand() % 45 + 5) / 10.0;
    direction = rand() % 360;
}

int Fish::getValue() const {
    return value;
}
