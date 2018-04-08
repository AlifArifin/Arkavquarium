#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include "Summonable.hpp"

using namespace std;

class Food : public Summonable {
    public:
        /*Sekawan*/
        Food();
        ~Food(); //destructor sekalian untuk menambah koin pemain

        /*Getter*/

        /*Setter*/

        /*Method*/
        void move(); //untuk pergerakan food
        void show(); //untuk display food
        
    private:
};

#endif