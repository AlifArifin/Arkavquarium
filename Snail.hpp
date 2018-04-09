#ifndef SNAIL_HPP
#define SNAIL_HPP

#include <iostream>
#include "Summonable.hpp"
#include "Matrix.hpp"

using namespace std;

class Snail : public Summonable{
    public:
        /*Sekawan*/
        Snail();

        /*Getter*/
        static int getSpeed_Snail();

        /*Setter*/

        /*Method*/
        void move(); //untuk pergerakan snail
        void show(); //untuk display snail

    private:
        static const int speed_snail; //mencatat kecepatan untuk Snail
};

#endif