#include "Guppy.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <cmath>
#include <cstddef>

using namespace std;

const int coin_time = 5;
const int grow_time = 2;
const int value_guppy = 100;  
const int value_coin = 10;

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
int Guppy::move(const ListObj<Food>& _l, const Matrix& m) {
    if (count_move == hunger_time) {
        hungry = true;
        count_move = 0;
    } else if (count_move == change_move) {
        count_move = 0;
        setChange_Move();
    }

    if (hungry) {
        if (!_l.isEmpty()) {
            double closest_food = _l.get(0).getPosition.distanceTo(position);
            int idx_food = 0;
            for (int i = 0; i < _l.size(); i++) {
                double temp = _l.get(i).getPosition().distanceTo(position);
                if (temp < closest_food) {
                    closest_food = temp;
                    idx_food = i;
                }
            }

            Food g = _l.get(idx_food);
            if (closest_food <= speed_fish) {
                position = g.getPosition();
                return g.getId();
            } else {
                double a = position.patan2(g.getPosition());
                position.setX(int(floor(position.getX() + speed_fish * cos(a))));
                position.setY(int(floor(position.getX() + speed_fish * sin(a))));

                return -1;
            }
        }
    } else {
        count_move++;

        position.setX(int(floor(position.getX() + speed_fish * cos(direction))));
        position.setY(int(floor(position.getX() + speed_fish * sin(direction))));

        if (position.isOutLeft(m)) {
            position.setY(0);
            count_move = 0;
            direction = rand() % 100 / 100.0 * PI - (PI/2);
        } else if (position.isOutRight(m)) {
            position.setY(m.getColumn() - 1);
            count_move = 0;
            direction = rand() % 100 / 100.0 * PI + (PI/2);
        }
        
        if (position.isOutTop(m)) {
            position.setX(0);
            count_move = 0;
            direction = rand() % 100 / 100.0 * PI + PI;
        } else if (position.isOutBottom(m)) {
            position.setX(m.getRow() - 1);
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

void show() {

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