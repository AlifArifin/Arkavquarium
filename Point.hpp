#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include "Matrix.hpp"

using namespace std;

class Point {
    public:
        /*Sekawan*/
        Point(double, double);

        /*Getter*/
        double getX() const;
        double getY() const;

        /*Setter*/
        void setX(double);
        void setY(double);

        /*Method*/
        Point& operator+(const Point&); //menambah this->point dengan point pada parameter
        double distanceTo(const Point&); //Menghitung jarak this-> point dengan point pada parameter
        bool isBottom(const Matrix&); //untuk mengecek apakah summonable terdapat di bawah aquarium
        bool isOutBottom(const Matrix&); //untuk mengecek apakah summonable terdapat di bawah aquarium
        bool isOutTop(const Matrix&); //untuk mengecek apakah summonable terdapat di atas aquarium
        bool isOutRight(const Matrix&); //untuk mengecek apakah summonable terdapat di kanan aquarium
        bool isOutLeft(const Matrix&); //untuk mengecek apakah summonable terdapat di kiri aquarium
        double patan2(const Point&);
        bool operator==(const Point&) const;

    private:
        double x, y;
};

#endif