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

        /*Setter*/

        /*Method*/
        void move(const Matrix &m); //untuk pergerakan food
        void show(); //untuk display food
        
    private:
};

#endif