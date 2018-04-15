#include <iostream>
#include "Matrix.hpp"

using namespace std;

const int Matrix::row = 480;
const int Matrix::column = 640;

Matrix::Matrix(){
	data = new int*[row];
    for (int x = 0; x < row; x++){
        data[x] = new int[column];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
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

int Matrix::getRow(){
    return row;
}

int Matrix::getColumn(){
    return column;
}

void Matrix::setVal(int m, int n, int val){
    data[m][n] = val;
}

int Matrix::getVal(int m, int n){
    return data[m][n];
}

   
        