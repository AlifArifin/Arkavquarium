#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

using namespace std;

class Matrix{
    public:
        Matrix();
        static int getRow();
        static int getColumn();

    private:
        const static int row;
        const static int column;
};

#endif