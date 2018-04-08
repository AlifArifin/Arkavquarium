#include "Piranha.hpp"
#include <iostream>

using namespace std;

static const int value_piranha = 100;

Piranha::Piranha() : Fish("piranha", value_piranha) {
}

void Piranha::move() {
    if (count_move == change_move) {
        setChange_Move();
        count_move = 0;
    } else {
        count_move++;
    }
}    

void Piranha::eat() {

}

Coin Piranha::dropCoin(const Guppy& _g) {
    int val = (_g.getPhase() + 1) * _g.getValue();
    Coin _c(val);    

    return _c;
}

void Piranha::show() {

}