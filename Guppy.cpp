#include "Guppy.hpp"
#include <iostream>

using namespace std;

const int coin_time = 5;
const int value_guppy = 100;  
const int value_coin = 10;


/*Sekawan*/
Guppy::Guppy(Point _p) : Fish("guppy", value_guppy, _p) {
    phase = 1;
}

/*Getter*/
int Guppy::getPhase() const {
    return phase;
}

int Guppy::getCoin_Time() const {
    return coin_time;
}

/*Setter*/
void Guppy::setPhase(int _p) {
    phase = _p;
}

/*Method*/
Food Guppy::move(const ListObj<Food>& _l, const Matrix& m) {
    if (count_move == hunger_time) {
        hungry = true;
        count_move = 0;
    } else if (count_move == change_move) {
        count_move = 0;
        setChange_Move();
    }

    if (hungry) {
        if (!_l.isEmpty()) {
            double closest_food = _l.get(0).position.distanceTo(position);
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
                return g;
            } else {
                double a = position.patan2(g.position);
                position.setX(int(floor(position.getX() + speed_fish * cos(a))));
                position.setY(int(floor(position.getX() + speed_fish * sin(a))));

                return NULL;
            }
        }
    } else {
        count_move++;

        position.setX(int(floor(position.getX() + speed_fish * cos(direction))));
        position.setY(int(floor(position.getX() + speed_fish * sin(direction))));

        if (position.isOutLeft()) {
            position.setY(0);
            count_move = 0;
            direction = rand() % M_PI - (M_PI/2);
        } else if (position.isOutRight()) {
            position.setY(m.getColumn() - 1);
            count_move = 0;
            direction = rand() % M_PI + (M_PI/2);
        }
        
        if (position.isOutTop()) {
            position.setX(0);
            count_move = 0;
            direction = rand() % M_PI + M_PI;
        } else if (position.isOutBottom() {
            position.setX(m.getRow() - 1);
            count_move = 0;
            direction = rand() % M_PI;
        }

        return NULL;
    }
}   

Coin Guppy::dropCoin() {
    Coin _c(value_coin * phase);

    return _c;
}

void Guppy::eat() {
    hungry = false;
}

void show() {

}