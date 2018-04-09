#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include "Matrix.hpp"

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
        bool isBottom(const Matrix&); //untuk mengecek apakah summonable terdapat di bawah aquarium
        bool isOutBottom(const Matrix&); //untuk mengecek apakah summonable terdapat di bawah aquarium
        bool isOutTop(const Matrix&); //untuk mengecek apakah summonable terdapat di atas aquarium
        bool isOutRight(const Matrix&); //untuk mengecek apakah summonable terdapat di kanan aquarium
        bool isOutLeft(const Matrix&); //untuk mengecek apakah summonable terdapat di kiri aquarium
        double patan2(const Point&);

    private:
        int x, y;
};

#endif