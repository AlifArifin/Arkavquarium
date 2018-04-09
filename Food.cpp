#include "Food.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

const int food_speed = 5;
const int value_food = 10;

/*Sekawan*/
Food::Food(Point P) : Summonable("food", food_speed, P) {
    direction = 3*M_PI/4;
}

Food::~Food() {} //destructor sekalian untuk menambah koin pemain

/*Getter*/
int Food::getValue_Food() {
    return value_food;
}

/*Setter*/

/*Method*/
void Food::move(const Matrix& m) { //untuk pergerakan food
    if (!position.isBottom(m)) {
        Point newPos(position.getX(), position.getY() + speed);
        if (newPos.isOutBottom(m)) {
            newPos.setY(m.getRow()-1);
            position = newPos;
        } else {
            position = newPos;
        }
    }
}

void Food::show() { //untuk display food

}
