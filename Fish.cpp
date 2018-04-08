#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Fish.hpp"
#include "Summonable.hpp"

using namespace std;

const static int hunger_time = 10;
const static int dead_time = 20;
const static int speed_fish = 8;

Fish::Fish(string _j, int _v, Point _p) : Summonable(_j, speed_fish, _p), value(_v) {
    hungry = false;
    food_count = 0;
    count_move = 0;
    setChange_Move();
}

Fish::~Fish() {

}

/*Getter*/
bool Fish::getHungry() const {
    return hungry;
}
int Fish::getFood_Count() const {
    return food_count;
}

static int getHunger_Time() {
    return hunger_time;
}

static int getDead_Time() {
    return dead_time;
} 

int Fish::getCount_Move() const {
    return count_move;
}

int Fish::getChange_Move() const {
    return change_move;
}

static int getSpeed_Fish() {
    return speed_fish;
}

/*Setter*/
void Fish::setHungry(bool _h) {
    hungry = _h;
}

void Fish::setFood_Count(int _f) {
    food_count = _f;
}

void Fish::setCount_Move(int _c) {
    count_move = _c;
}

void Fish::setChange_Move() {
    change_move = rand() % 45 + 5;
}