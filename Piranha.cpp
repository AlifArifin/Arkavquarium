#include "Piranha.hpp"
#include "ListObj.hpp"
#include <iostream>
#include <cmath>
#include "time.h"

using namespace std;

const int Piranha::value_piranha = 100;

Piranha::Piranha(Point _p) : Fish("piranha", value_piranha, _p) {
}

Guppy Piranha::move(const ListObj<Guppy>& _l, const Matrix& m) {
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

            Guppy g = _l.get(idx_food);
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

void Piranha::eat() {
    hungry = false;
}

Coin Piranha::dropCoin(const Guppy& _g) {
    int val = (_g.getPhase() + 1) * _g.getValue();
    Coin _c(val);    

    return _c;
}

void Piranha::show() {

}