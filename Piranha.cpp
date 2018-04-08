#include "Piranha.hpp"
#include <iostream>

using namespace std;

static const int value_piranha = 100;

Piranha::Piranha() : Fish("piranha", value_piranha) {
}

Guppy Piranha::move(ListObj<Guppy> _l) {
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

void Piranha::eat() {

}

Coin Piranha::dropCoin(const Guppy& _g) {
    int val = (_g.getPhase() + 1) * _g.getValue();
    Coin _c(val);    

    return _c;
}

void Piranha::show() {

}