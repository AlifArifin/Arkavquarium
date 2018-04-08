#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

using namespace std;

class Point {
    public:
        /*Sekawan*/
        Point(int, int);

        /*Getter*/
        int getX() const;
        int getY() const;

        /*Setter*/
        void setX(int);
        void setY(int);

        /*Method*/
        Point& operator+(const Point&); //menambah this->point dengan point pada parameter
        double distanceTo(const Point&); //Menghitung jarak this-> point dengan point pada parameter
        bool isInRange(Point&); //untuk mengecek apakah summonable terdapat dalam range atau tidak
        bool isBottom(Point&); //untuk mengecek apakah summonable terdapat di bawah aquarium (untuk food dan coin)

    private:
        int x, y;
};

#endif