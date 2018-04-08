#include <iostream>
#include "Matrix.hpp"

using namespace std;

const static int row = 10;
const static int column = 10;

Matrix::Matrix(int row, int column){
	allocArray();
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			data[i][j] = 0;
		}
	}
}

Matrix::~Matrix(){
	for(int i = 0; i < row; i++)
	{
		delete [] data[i];
	}
	delete [] data;
}

static int getRow(){
    return row;
}

static int getColumn(){
    return column;
}

void Matrix::setVal(int m, int n, int val){
    data[m][n] = val;
}

   
        