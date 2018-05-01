#include "Piranha.hpp"
#include "ListObj.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int Piranha::value_piranha = 300;
const int Piranha::radius_piranha = 35;
const string Piranha::image_piranha[4] = {"img/LPiranha.png", "img/RPiranha.png", "img/LHungryPiranha.png", "img/RHungryPiranha.png"};

Piranha::Piranha(Point _p) : Fish(value_piranha, _p) {
    image = image_piranha[0];
}

int Piranha::move(const ListObj<Guppy>& _l, const Matrix& m, double time) {
    count_move += time;
    change_move -= time;

    if (count_move >= hunger_time && !hungry) {
        hungry = true;
    } else if (count_move >= dead_time) {
        return -2;
    } else if (change_move <= 0 && !hungry) {
        setChange_Move();
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

        double a = position.patan2(g.getPosition());
        int dir = (int (a * 180.0/PI) % 360 + 360) % 360;
        setDirection(dir); 
        
        if (g.getPosition().isInRadius(position, radius_piranha + Guppy::getRadius_Guppy() * g.getPhase())) {
            count_move = 0;
            return _l.find(g);
        } else {
            position.setX(position.getX() + speed_fish * cos(a) * time);
            position.setY(position.getY() + speed_fish * sin(a) * time);
            return -1;
        }
    } else {
        double rad = PI/180 * direction;
        
        position.setX(position.getX() + speed_fish * cos(rad) * time);
        position.setY(position.getY() + speed_fish * sin(rad) * time);
        
        if (position.isOutLeft(m, radius_piranha)) {
            position.setX(radius_piranha);
            direction = (rand() % 180 - 90 ) % 360;
        } else if (position.isOutRight(m, radius_piranha)) {
            position.setX(m.getColumn() - 1 - radius_piranha);
            direction = rand() % 180 + 90;
        }
        
        if (position.isOutTop(m, radius_piranha)) {
            position.setY(radius_piranha);
            direction = rand() % 180;
        } else if (position.isOutBottom(m, radius_piranha)) {
            position.setY(m.getRow() - 1 - radius_piranha);
            direction = rand() % 180 + 180;
        }
        
        setDirection(direction);    
        
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

int Piranha::getValue_Piranha() {
    return value_piranha;
}

bool Piranha::operator==(const Piranha& p) const {
    return p.hungry == hungry && /*p.count_move == p.count_move && change_move == p.change_move && */ position == p.position &&direction == p.direction;
}

int Piranha::getRadius_Piranha() {
    return radius_piranha;
}

void Piranha::setDirection(int d) {
    if (!hungry) {
        if (d >= 90 && d <= 270) {
            image = image_piranha[0];
        } else {
            image = image_piranha[1];
        }
    } else {
        if (d >= 90 && d <= 270) {
            image = image_piranha[2];
        } else {
            image = image_piranha[3];
        }
    }
    direction = d;
}

string Piranha::getImage() {
    return image;
}