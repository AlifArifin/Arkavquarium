#include "Food.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

const int Food::speed_food = 5;
const int Food::value_food = 10;

/*Sekawan*/
Food::Food(Point P) : Summonable("food", speed_food, P) {
    direction = 270;
}

Food::~Food() {} //destructor sekalian untuk menambah koin pemain

/*Getter*/
int Food::getValue_Food() {
    return value_food;
}

/*Setter*/

/*Method*/
bool Food::move(const Matrix& m) { //untuk pergerakan food
    if (!position.isBottom(m)) {
        Point newPos(position.getX(), position.getY() + speed);
        if (newPos.isOutBottom(m)) {
            newPos.setY(m.getRow()-1);
            position = newPos;
        } else {
            position = newPos;
        }
        return true;
    } else {
        return false;
    }
}

void Food::show() { //untuk display food

}

bool Food::operator==(const Food& f) const {
    return f.position == position && f.direction == direction;
}
