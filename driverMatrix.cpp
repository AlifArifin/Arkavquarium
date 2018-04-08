#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main(){
    Matrix M;

    for(int i = 0; i < M.getRow(); i++){
        for(int j = 0; j < M.getColumn(); j++){
            int x = M.getVal(i, j);
            cout << x << endl;
        }
    }

    cout << "Tes" << endl;

    return 0;
}