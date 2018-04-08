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
Food Guppy::move(ListObj<Food> _l) {
    if (count_move == hunger_time) {
        hungry = true;
        count_move = 0;
    } else if (count_move == change_move) {
        count_move = 0;
        setChange_Move();
    }

    if (hungry) {
        
    } else {
        count_move++;

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