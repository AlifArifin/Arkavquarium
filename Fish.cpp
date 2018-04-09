#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Fish.hpp"
#include "Summonable.hpp"

using namespace std;

const int hunger_time = 10;
const int dead_time = 20;
const int speed_fish = 8;

Fish::Fish(string _j, int _v, Point _p) : Summonable(_j, speed_fish, _p), value(_v) {
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

int Fish::getCount_Move() const {
    return count_move;
}

int Fish::getChange_Move() const {
    return change_move;
}

int Fish::getSpeed_Fish() {
    return speed_fish;
}

/*Setter*/
void Fish::setHungry(bool _h) {
    hungry = _h;
}


void Fish::setCount_Move(int _c) {
    count_move = _c;
}

void Fish::setChange_Move() {
    change_move = rand() % 45 + 5;
}