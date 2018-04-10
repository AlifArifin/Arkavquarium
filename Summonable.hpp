#ifndef SUMMONABLE_HPP
#define SUMMONABLE_HPP

#include <iostream>
#include "Point.hpp"

using namespace std;

class Summonable {
    public:
        /*Sekawan*/
        Summonable(string, int, Point);    //menerima jenis, speed, dan lokasi spawn
        virtual ~Summonable();

        /*Getter*/
        Point getPosition() const;
        int getDirection() const;
        int getSpeed() const;

        /*Setter*/
        void setPosition(const Point&);
        void setDirection(int);

        /*Method*/      
        virtual void show() = 0; //untuk display summonable
        
    protected:
        Point position; //mencatat posisi dari summonable pada point
        int direction;  //direction harus berada pada angka 0 <= direction <= 360        
        int speed; //kecepatan dari Summonable
        string jenis; //menunjukkan jenis dari summonable
        static const double PI;
};

#endif