#include "Piranha.hpp"
#include "ListObj.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int Piranha::value_piranha = 100;

Piranha::Piranha(Point _p) : Fish("piranha", value_piranha, _p) {
}

int Piranha::move(const ListObj<Guppy>& _l, const Matrix& m) {
    if (count_move == hunger_time) {
        hungry = true;
        count_move = 0;
    } else if (count_move == change_move) {
        count_move = 0;
        setChange_Move();
    }

    if (hungry) {
        if (!_l.isEmpty()) {
            double closest_food = _l.get(0).getPosition().distanceTo(position);
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
                return _l.find(g);
            } else {
                double a = position.patan2(g.getPosition());
                position.setX(int(floor(position.getX() + speed_fish * cos(a))));
                position.setY(int(floor(position.getX() + speed_fish * sin(a))));

                return -1;
            }
        }
    } else {
        count_move++;

        double rad = PI/180 * direction;
        position.setX(int(floor(position.getX() + speed_fish * cos(rad))));
        position.setY(int(floor(position.getX() + speed_fish * sin(rad))));

        if (position.isOutLeft(m)) {
            position.setY(0);
            count_move = 0;
            direction = rand() % 180 % 360;
        } else if (position.isOutRight(m)) {
            position.setY(m.getColumn() - 1);
            count_move = 0;
            direction = rand() % 180 + 90;
        }
        
        if (position.isOutTop(m)) {
            position.setX(0);
            count_move = 0;
            direction = rand() % 180 + 180;
        } else if (position.isOutBottom(m)) {
            count_move = 0;
            direction = rand() % 180;
        }

        return -1;
    }
}    

void Piranha::eat() {
    hungry = false;
}

Coin Piranha::dropCoin(const Guppy& _g) {
    int val = (_g.getPhase() + 1) * _g.getValue();
    Coin _c(position, val);    

    return _c;
}

void Piranha::show() {

}

int Piranha::getValue_Piranha() {
    return value_piranha;
}

bool Piranha::operator==(const Piranha& p) const {
    return p.hungry == hungry && p.count_move == p.count_move && change_move == p.change_move && position == p.position &&direction == p.direction;
}
