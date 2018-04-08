#include "Guppy.hpp"
#include <iostream>

using namespace std;

const static int coin_time = 5;
const static int value_guppy = 100;  
const static int value_coin = 10;


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
void Guppy::move(ListObj<Food> _l) {
    if (count_move == hunger_time) {
        hungry = true;
    }

    if (hungry) {
        
    } else {
        if (count_move == change_move) {
            setChange_Move();
            count_move = 0;
        } else {
            count_move++;
        }
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