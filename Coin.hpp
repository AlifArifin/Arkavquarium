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
        void move(const Matrix &M); //untuk pergerakkan koin
        void show(); //untuk menampilkan koin
        bool operator== (const Coin&) const;

    private:
        const int value;
};

#endif