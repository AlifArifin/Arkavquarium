#include "Food.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

const int Food::speed_food = 30;
const int Food::value_food = 10;
const int Food::radius_food = 20;
const string Food::image = "Food.png";

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
bool Food::move(const Matrix& m, double time) { //untuk pergerakan food
    if (!position.isOutBottom(m, radius_food)) {
        position.setY(position.getX() + speed * time);
        return position.isOutBottom(m, radius_food);
    } else {
        return false;
    }
}

void Food::show() { //untuk display food

}

bool Food::operator==(const Food& f) const {
    return f.position == position && f.direction == direction;
}

int Food::getRadius_Food() {
    return radius_food;
}

string Food::getImage() {
    return image;
}
