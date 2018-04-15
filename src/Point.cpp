#include <iostream>
#include "Point.hpp"
#include "Matrix.hpp"
#include <math.h>

using namespace std;

/*Sekawan*/
Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

/*Getter*/
double Point::getX() const{
    return x;
}

double Point::getY() const{
    return y;
}

/*Setter*/
void Point::setX(double x){
    this->x = x;
}

void Point::setY(double y){
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
    return sqrt((p.x  - this->x) * (p.x  - this->x) + (p.y  -  this->y) * (p.y  -  this->y));
}

bool Point::isBottom(const Matrix& m, int r) {
    return int(y) == m.getRow() - 1 - r;
}

bool Point::isOutBottom(const Matrix& m, int r) {
    //untuk mengecek apakah summonable terdapat di bawah aquarium (untuk food dan coin)
    return int(y) > m.getRow() - 1 - r; 
}

bool Point::isOutTop(const Matrix& m, int r){
    //untuk mengecek apakah summonable terdapat di atas aquarium
    return int(y) < r;
}

bool Point::isOutRight(const Matrix& m, int r){ 
    //untuk mengecek apakah summonable terdapat di kanan aquarium
    return int(x) > m.getColumn() - 1 - r;
}

bool Point::isOutLeft(const Matrix& m, int r){
    //untuk mengecek apakah summonable terdapat di kiri aquarium
    return int(x) < r;
}       
double Point::patan2(const Point& p) {
    return atan2(p.y - y, p.x - x); 
}

bool Point::operator==(const Point& p) const {
    int absis = (int)x;
    int ordinat = (int)y;
    return absis == (int)p.x && ordinat == (int)p.y;
}

bool Point::isInRadius(const Point& p , int r) {
    return int(sqrt((p.x  - this->x) * (p.x  - this->x) + (p.y  -  this->y) * (p.y  -  this->y))) <= r;
}
