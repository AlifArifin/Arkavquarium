#include <iostream>
#include "Snail.hpp"

using namespace std;

const int Snail::speed_snail = 20;
const int Snail::radius_snail = 40;
const string Snail::image_snail[2] = {"LSnail.png", "RSnail.png"};

/*Sekawan*/
Snail::Snail(Point p) : Summonable("snail", speed_snail, p){ 
    image = image_snail[0];
}

/*Getter*/
int Snail::getSpeed_Snail(){
    return speed_snail;
}

/*Setter*/

/*Method*/
int Snail::move(const ListObj<Coin>& _l, double time){
    //untuk pergerakan snail
    if(!_l.isEmpty()){
        double closest_coin = _l.get(0).getPosition().getY();
        int idx_coin = 0;
        for (int i = 0; i < _l.size(); i++) {
            double temp = _l.get(i).getPosition().getY();
            if (temp < closest_coin) {
                closest_coin = temp;
                idx_coin = i;
            }
        }

        Coin c = _l.get(idx_coin);

        double a = position.patan2(c.getPosition());
        setDirection(a * 180.0/PI);

        if (position.isInRadius(c.getPosition(), Coin::getRadius_Coin() + radius_snail)) {
            return _l.find(c);
        } else if (position.getX() == c.getPosition().getX()) {
            return -1;
        } else {
            position.setX(c.getPosition().getX() + speed_snail * time);
            return -1;
        }
    } else {
        return -1;
    }
}

void Snail::show(){} //untuk display snail

bool Snail::operator==(const Snail& s) const {
    return s.position == position && s.direction == direction;
}

int Snail::getRadius_Snail() {
    return radius_snail;
}

string Snail::getImage() const {
    return image;
}

void Snail::setDirection(int d) {
    if (d >= 90 && d <= 270) {
        direction = 180;
        image = image_snail[0];
    } else {
        direction = 0;
        image = image_snail[1];
    }
}

