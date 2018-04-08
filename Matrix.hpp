#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

using namespace std;

class Matrix{
    public:
        Matrix();
        ~Matrix();
        static int getRow();
        static int getColumn();
        void setVal(int m, int n);
        int getVal(int m, int n);

    private:
        const static int row;
        const static int column;
        int **data;
        //allocate the array
	    /*void allocArray(){
		    data = new int*[row];
		    for(int i = 0; i < row; i++)
		    {
			    data[i] = new int[column];
		    }
	    }*/
};

#endif