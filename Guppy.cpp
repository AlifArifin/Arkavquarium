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
const int Guppy::radius_guppy = 15;
const string Guppy::image_guppy[3][4] = { {"LGuppy1.png", "RGuppy1.png", "LHungryGuppy1.png", "RHungryGuppy1.png"}, 
                                          {"LGuppy2.png", "RGuppy2.png", "LHungryGuppy2.png", "RHungryGuppy2.png"}, 
                                          {"LGuppy3.png", "RGuppy3.png", "LHungryGuppy3.png", "RHungryGuppy3.png"} };

/*Sekawan*/
Guppy::Guppy(Point _p) : Fish("guppy", value_guppy, _p) {
    phase = 1;
    food_count = 0;
    image = image_guppy[0][0];
    coin_count = 0;
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
    change_move -= time;
    coin_count += time;

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

        Food g = _l.get(idx_food);

        double a = position.patan2(g.getPosition());
        int dir = (int (a * 180.0/PI) % 360 + 360) % 360;
        setDirection(dir);

        draw_text(to_string(dir), 18, 15, 300, 0, 0, 0);
        draw_text(to_string(count_move) + " " + to_string(change_move), 18, 15, 30, 0, 0, 0);

        if (g.getPosition().isInRadius(position, radius_guppy * phase + Food::getRadius_Food())) {
            count_move = 0;
            return _l.find(g);
        } else {
            position.setX(position.getX() + speed_fish * cos(a) * time);
            position.setY(position.getY() + speed_fish * sin(a) * time);
            return -1;
        }
    } else {
        double rad = PI/180 * direction;
        setDirection(direction);
        draw_text(to_string(count_move) + " " + to_string(change_move), 18, 15, 30, 0, 0, 0);
        
        position.setX(position.getX() + speed_fish * cos(rad) * time);
        position.setY(position.getY() + speed_fish * sin(rad) * time);

        draw_text(to_string(position.getX()), 18, 15, 60, 0, 0, 0);
        draw_text(to_string(position.getY()), 18, 15, 90, 0, 0, 0);

        if (position.isOutLeft(m, radius_guppy * phase)) {
            position.setX(radius_guppy * phase);
            direction = (rand() % 180 - 90 ) % 360;
        } else if (position.isOutRight(m, radius_guppy * phase)) {
            position.setX(m.getColumn() - 1 - radius_guppy * phase);
            direction = rand() % 180 + 90;
        }
        
        if (position.isOutTop(m, radius_guppy * phase)) {
            position.setY(radius_guppy * phase);
            direction = rand() % 180;
        } else if (position.isOutBottom(m, radius_guppy * phase)) {
            position.setY(m.getRow() - 1 - radius_guppy * phase);
            direction = rand() % 180 + 180;
        }

        setDirection(direction);
        
        return -1;
    }
}   

Coin Guppy::dropCoin() {
    coin_count = 0;
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

void Guppy::setDirection(int d) {
    if (!hungry) {
        if (d >= 90 && d <= 270) {
            image = image_guppy[phase - 1][0];
        } else {
            image = image_guppy[phase - 1][1];
        }
    } else {
        if (d >= 90 && d <= 270) {
            image = image_guppy[phase - 1][2];
        } else {
            image = image_guppy[phase - 1][3];
        }
    }

    direction = d;
}

string Guppy::getImage() {
    return image;
}

double Guppy::getCoin_Count() {
    return coin_count;
}
