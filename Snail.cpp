#include <iostream>
#include "Summonable.hpp"
#include "Snail.hpp"

using namespace std;

/*Sekawan*/
Snail::Snail();

        /*Getter*/
        static int getSpeed_Snail();

        /*Setter*/

        /*Method*/
        void move(); //untuk pergerakan snail
        void show(); //untuk display snail

    private:
        static const int speed_snail; //mencatat kecepatan untuk Snail