#ifndef SNAIL_HPP
#define SNAIL_HPP

#include <iostream>
#include "Summonable.hpp"
#include "Matrix.hpp"
#include "ListObj.hpp"
#include "Coin.hpp"

using namespace std;

class Snail : public Summonable{
    public:
        /*Sekawan*/
        Snail(Point);

        /*Getter*/
        static int getSpeed_Snail();

        /*Setter*/

        /*Method*/
        int move(const ListObj<Coin>&); //untuk pergerakan snail
        void show(); //untuk display snail
        bool operator==(const Snail&) const;

    private:
        static const int speed_snail; //mencatat kecepatan untuk Snail
};

#endif