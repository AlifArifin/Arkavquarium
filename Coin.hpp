#ifndef COIN_HPP
#define COIN_HPP

#include <iostream>
#include "Summonable.hpp"

using namespace std;

class Coin : public Summonable {
    public:
        /*Sekawan*/
        Coin(Point P, int _val);
        ~Coin(); //destructor sekalian untuk menambah koin pemain

        /*Getter*/

        /*Setter*/

        /*Method*/
        void move(); //untuk pergerakkan koin
        void show(); //untuk menampilkan koin
    
    private:
        const int value;
};

#endif