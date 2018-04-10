#include "Coin.hpp"
#define _USE_MATH_DEFINES

#include <math.h>

const int coin_speed = 5;

/*Sekawan*/
Coin::Coin(Point P, int _val) : Summonable("coin", coin_speed, P), value(_val) {
    direction = 270;
}

Coin::~Coin() { //destructor sekalian untuk menambah koin pemain
    
}
/*Getter*/

/*Setter*/

/*Method*/
void Coin::move(const Matrix &M) { //untuk pergerakkan koin
    if (!position.isBottom(M)) {
        Point newPos(position.getX(), position.getY() + speed);
        if (newPos.isOutBottom(M)) {
            newPos.setY(M.getRow()-1);
            position = newPos;
        } else {
            position = newPos;
        }
    }
}

void Coin::show() {} //untuk menampilkan koin

bool Coin::operator== (const Coin& c) const {
    return c.value == value && c.position == position && direction == c.direction;
}

