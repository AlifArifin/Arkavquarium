#include <iostream>
#include "Point.hpp"
#include "Summonable.hpp"

using namespace std;

/*Sekawan*/
Summonable::Summonable(int id, string jenis, int speed, Point position){    
    //menerima id, jenis, speed, dan lokasi spawn
    this->id = id;
    this->jenis = jenis;
    this->speed = speed;
    this->position = position;
    direction = 0;        
    id_count ++; 
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
        
static int Summonable::getId_Count(){
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

static void Summmonable::setId(int id){
    this->id = id;
}

    