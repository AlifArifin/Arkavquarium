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
        static int getRadius_Snail();
        string getImage() const;

        /*Setter*/
        void setDirection(int);

        /*Method*/
        int move(const ListObj<Coin>&, double); //untuk pergerakan snail
        void show(); //untuk display snail
        bool operator==(const Snail&) const;

    private:
        static const int speed_snail; //mencatat kecepatan untuk Snail
        static const int radius_snail;
        static const string image_snail[2];
        string image;
};

#endif