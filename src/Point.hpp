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
        bool isBottom(const Matrix&, int); //untuk mengecek apakah summonable terdapat di bawah aquarium
        bool isOutBottom(const Matrix&, int); //untuk mengecek apakah summonable terdapat di bawah aquarium
        bool isOutTop(const Matrix&, int); //untuk mengecek apakah summonable terdapat di atas aquarium
        bool isOutRight(const Matrix&, int); //untuk mengecek apakah summonable terdapat di kanan aquarium
        bool isOutLeft(const Matrix&, int); //untuk mengecek apakah summonable terdapat di kiri aquarium
        double patan2(const Point&);
        bool operator==(const Point&) const;
        bool isInRadius(const Point&, int);

        friend ostream& operator<< (ostream& os, const Point& P) {
            os << "(" << P.x << "," << P.y << ")";
            return os;
        }

        friend istream& operator>> (istream& is, Point& P) {
            is >> P.x >> P.y;
            return is;
        }

    private:
        double x, y;
};

#endif