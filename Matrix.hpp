#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

using namespace std;

class Matrix{
    private:
        const static int row;
        const static int column;
        int **data;

    public:
        Matrix();
        ~Matrix();
        static int getRow();
        static int getColumn();
        void setVal(int m, int n, int val);
        int getVal(int m, int n);

};

#endif