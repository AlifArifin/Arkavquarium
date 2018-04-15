#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main(){
    Matrix mat;

    for(int i = 0; i < mat.getRow(); i++){
        for(int j = 0; j < mat.getColumn(); j++){
            int x = mat.getVal(i, j);
            cout << x;
        }
        cout << endl;
    }

    cout << "Tes" << endl;

    return 0;
}