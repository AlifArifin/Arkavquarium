#include "Guppy.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const int Guppy::coin_time = 5;
const int Guppy::grow_time = 2;
const int Guppy::value_guppy = 100;  
const int Guppy::value_coin = 10;
const int Guppy::radius_guppy = 4;

/*Sekawan*/
Guppy::Guppy(Point _p) : Fish("guppy", value_guppy, _p) {
    phase = 1;
    food_count = 0;
}

/*Getter*/
int Guppy::getPhase() const {
    return phase;
}

int Guppy::getCoin_Time() {
    return coin_time;
}

/*Setter*/
void Guppy::setPhase(int _p) {
    phase = _p;
}

/*Method*/
int Guppy::move(const ListObj<Food>& _l, const Matrix& m, double time) {
    count_move += time;

    if (count_move >= hunger_time) {
        hungry = true;
    } else if (count_move >= change_move && !hungry) {
        count_move = 0;
        setChange_Move();
    } else if (count_move >= dead_time) {
        return -2;
    }

    if (hungry && !_l.isEmpty()) {
        double closest_food = _l.get(0).getPosition().distanceTo(position);
        int idx_food = 0;
        for (int i = 0; i < _l.size(); i++) {
            double temp = _l.get(i).getPosition().distanceTo(position);
            if (temp < closest_food) {
                closest_food = temp;
                idx_food = i;
            }
        }

        Food g = _l.get(idx_food);

        if (g.getPosition().isInRadius(position, radius_guppy + Food::getRadius_Food())) {
            position = g.getPosition();
            count_move = 0;
            return _l.find(g);
        } else {
            double a = position.patan2(g.getPosition());
            position.setX(position.getX() + speed_fish * cos(a) * time);
            position.setY(position.getX() + speed_fish * sin(a) * time);
            return -1;
        }
    } else {
        double rad = PI/180 * direction;
        position.setX(position.getX() + speed_fish * cos(rad) * time);
        position.setY(position.getY() + speed_fish * sin(rad) * time);

        if (position.isOutLeft(m, radius_guppy)) {
            position.setY(radius_guppy);
            count_move = 0;
            direction = rand() % 100 / 100.0 * PI - (PI/2);
        } else if (position.isOutRight(m, radius_guppy)) {
            position.setY(m.getColumn() - 1 - radius_guppy);
            count_move = 0;
            direction = rand() % 100 / 100.0 * PI + (PI/2);
        }
        
        if (position.isOutTop(m, radius_guppy)) {
            position.setX(radius_guppy);
            count_move = 0;
            direction = rand() % 100 / 100.0 * PI + PI;
        } else if (position.isOutBottom(m, radius_guppy)) {
            position.setX(m.getRow() - 1 - radius_guppy);
            count_move = 0;
            direction = rand() % 100 / 100.0 * PI;
        }

        return -1;
    }
}   

Coin Guppy::dropCoin() {
    int val = value_coin * phase;
    Coin _c(position, val);    

    return _c;
}

void Guppy::eat() {
    hungry = false;
    food_count++;
    
    if (food_count == grow_time * phase && phase != 3) {
        phase++;
        food_count = 0;
    }
}

void Guppy::show() {

}

int Guppy::getFood_Count() const {
    return food_count;
}


void Guppy::setFood_Count(int _f) {
    food_count = _f;
}

int Guppy::getValue_Guppy() {
    return value_guppy;
}

bool Guppy::operator==(const Guppy& g1) const {
    return g1.phase == phase && g1.food_count == food_count && g1.hungry == hungry && /* g1.count_move == g1.count_move && change_move == g1.change_move && */ position == g1.position && direction == g1.direction;
}

int Guppy::getRadius_Guppy() {
    return radius_guppy;
}