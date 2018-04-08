#include <iostream>
#include "Point.hpp"
#include <Math.h>

using namespace std;

/*Sekawan*/
Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

/*Getter*/
int Point::getX() const{
    return x;
}

int Point::getY() const{
    return y;
}

/*Setter*/
void Point::setX(int x){
    this->x = x;
}

void Point::setY(int y){
    this->y = y;
}

/*Method*/
Point& Point::operator+(const Point& p){ 
    //menambah this->point dengan point pada parameter
    this->x += p.x;
    this->y += p.y;
    return *this; 
}

double Point::distanceTo(const Point& p){
    //Menghitung jarak this-> point dengan point pada parameter
    return sqrt((p.x  - this.x) * (p.x  - this.x) + (p.y  -  this.y) * (p.y  -  this.y));
}

bool isInRange(){
    //untuk mengecek apakah summonable terdapat dalam range atau tidak
    return 
}

bool isBottom() {

} //untuk mengecek apakah summonable terdapat di bawah aquarium (untuk food dan coin)

double Point::patan2(const Point& p) {
    return atan2(p.y - y, p.x - x); 
}