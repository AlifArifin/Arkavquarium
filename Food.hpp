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

        /*Setter*/

        /*Method*/
        bool move(const Matrix &m); //untuk pergerakan food
        void show(); //untuk display food
        
        bool operator== (const Food& F) const;

    private:
        static const int value_food; //harga makanan
};

#endif