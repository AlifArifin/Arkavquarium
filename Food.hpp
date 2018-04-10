#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include "Summonable.hpp"

using namespace std;

class Food : public Summonable {
    public:
        /*Sekawan*/
        Food(Point P);
        ~Food(); //destructor sekalian untuk menambah koin pemain

        /*Getter*/
        static int getValue_Food();
        static int getRadius_Food();

        /*Setter*/

        /*Method*/
        bool move(const Matrix&, double); //untuk pergerakan food
        void show(); //untuk display food
        bool operator==(const Food&) const;

    private:
        static const int value_food; //harga makanan
        static const int speed_food;
        static const int radius_food;
};

#endif