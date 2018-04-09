#include <iostream>
#include "Snail.hpp"

using namespace std;

const int Snail::speed_snail = 10;

/*Sekawan*/
Snail::Snail(Point p) : Summonable("snail", speed_snail, p){ 
}

/*Getter*/
int Snail::getSpeed_Snail(){
    return speed_snail;
}

/*Setter*/

/*Method*/
int move(const ListObj<Coin>& _l){
    //untuk pergerakan snail
    if(!_l.isEmpty()){
        double closest_coin = _l.get(0).position.distanceTo(position);
        int idx_coin = 0;
        for (int i = 0; i < _l.size(); i++) {
            double temp = _l.get(i).getPosition().distanceTo(position);
            if (temp < closest_coin) {
                closest_coin = temp;
                idx_coin = i;
            }
        }
        Coin c = _l.get(idx_coin);
        if (closest_coin <= speed_snail) {
            position.setX(c.getPosition().getX());
            return c.getId();
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

void show(); //untuk display snail

