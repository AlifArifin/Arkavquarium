#include "Coin.hpp"
#define _USE_MATH_DEFINES

#include <math.h>

const int Coin::speed_coin = 20;
const int Coin::radius_coin = 15;
const string Coin::image = "Coin.png";

/*Sekawan*/
Coin::Coin(Point P, int _val) : Summonable(speed_coin, P), value(_val) {
    direction = 270;
}

Coin::~Coin() { //destructor sekalian untuk menambah koin pemain
    
}
/*Getter*/
int Coin::getRadius_Coin() {
    return radius_coin;
}

int Coin::getSpeed_Coin() {
    return speed_coin;
}

/*Setter*/

/*Method*/
void Coin::move(const Matrix &M, double time) { //untuk pergerakkan koin
    if (!position.isBottom(M, radius_coin)) {
        position.setY(position.getY() + speed * time);
        if (position.isOutBottom(M, radius_coin)) {
            position.setY(M.getRow() - 1 - radius_coin);
        }    
    }
}

bool Coin::operator== (const Coin& c) const {
    return c.value == value && c.position == position && direction == c.direction;
}

string Coin::getImage() {
    return image;
}

int Coin::getValue() {
    return value;
}

