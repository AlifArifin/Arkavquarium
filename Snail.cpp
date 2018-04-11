#include <iostream>
#include "Snail.hpp"

using namespace std;

const int Snail::speed_snail = 15;
const int Snail::radius_snail = 22;
const string Snail::image_snail[2] = {"LSnail.png", "RSnail.png"};

/*Sekawan*/
Snail::Snail(Point p) : Summonable(speed_snail, p){ 
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
    position.setY(480 - radius_snail - 1);
    if(!_l.isEmpty()){
        Point closest_coin = _l.get(0).getPosition();
        int idx_coin = 0;
        for (int i = 0; i < _l.size(); i++) {
            Point temp = _l.get(i).getPosition();
            if (position.isInRadius(temp, Coin::getRadius_Coin() + radius_snail)) {
                return i;
            } else if (int(temp.getY()) > int(closest_coin.getY())) {
                closest_coin = temp;
                idx_coin = i;
            } else if (int(temp.getY()) == int(closest_coin.getY())) {
                if (position.distanceTo(temp) < position.distanceTo(closest_coin)) {
                    closest_coin = temp;
                    idx_coin = i;
                }
            }
        }

        Coin c = _l.get(idx_coin);

        double a = position.patan2(c.getPosition());
        int dir = (int (a * 180.0/PI) % 360 + 360) % 360;
        setDirection(dir);

        if (position.isInRadius(c.getPosition(), Coin::getRadius_Coin() + radius_snail)) {
            return idx_coin;
        } else if (int(position.getX()) == int(c.getPosition().getX())) {
            return -1;
        } else {
            position.setX(position.getX() + speed_snail * cos(direction * PI/180) * time);
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

