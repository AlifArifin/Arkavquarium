#include <iostream>
#include "Point.hpp"
#include "Summonable.hpp"
#include "Matrix.hpp"

using namespace std;

const double PI = 3.14159265;
int id_count = 1;

/*Sekawan*/
Summonable::Summonable(string jenis, int _s, Point position) : id(id_count), speed(_s) {    
    //menerima id, jenis, speed, dan lokasi spawn
    id_count ++;
    this->jenis = jenis;
    this->position = position;
    direction = 0;         
}

/*Destructor*/
Summonable::~Summonable(){}

/*Getter*/
Point Summonable::getPosition() const{
    return position;
}

int Summonable::getDirection() const{
    return direction;
}
        
int Summonable::getSpeed() const{
    return speed;
}
        
int Summonable::getId_Count(){
    return id_count;
}
        
int Summonable::getId() const{
    return id;
}

/*Setter*/
void Summonable::setPosition(const Point& p){
    position = p;
}

void Summonable::setDirection(int direction){
    this->direction = direction;
}
    