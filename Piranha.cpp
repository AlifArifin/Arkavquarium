#include "Piranha.hpp"
#include "ListObj.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int Piranha::value_piranha = 100;
const int Piranha::radius_piranha = 5;

Piranha::Piranha(Point _p) : Fish("piranha", value_piranha, _p) {
}

int Piranha::move(const ListObj<Guppy>& _l, const Matrix& m, double time) {
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

        Guppy g = _l.get(idx_food);
        
        if (g.getPosition().isInRadius(position, radius_piranha + Guppy::getRadius_Guppy())) {
            position = g.getPosition();
            count_move = 0;
            return _l.find(g);
        } else {
            double a = position.patan2(g.getPosition());
            position.setX(position.getX() + speed_fish * cos(a) * time);
            position.setY(position.getY() + speed_fish * sin(a) * time);
            return -1;
        }
    } else {
        double rad = PI/180 * direction;
        position.setX(position.getX() + speed_fish * cos(rad) * time);
        position.setY(position.getX() + speed_fish * sin(rad) * time);

        if (position.isOutLeft(m, radius_piranha)) {
            position.setY(radius_piranha);
            count_move = 0;
            direction = rand() % 180 % 360;
        } else if (position.isOutRight(m, radius_piranha)) {
            position.setY(m.getColumn() - 1 - radius_piranha);
            count_move = 0;
            direction = rand() % 180 + 90;
        }
        
        if (position.isOutTop(m, radius_piranha)) {
            position.setX(radius_piranha);
            count_move = 0;
            direction = rand() % 180 + 180;
        } else if (position.isOutBottom(m, radius_piranha)) {
            position.setX(m.getRow() - 1 - radius_piranha);
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
    return p.hungry == hungry && /*p.count_move == p.count_move && change_move == p.change_move && */ position == p.position &&direction == p.direction;
}

int Piranha::getRadius_Piranha() {
    return radius_piranha;
}
