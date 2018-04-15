#include <iostream>
#include "Account.hpp"

using namespace std;

int main(){
    Account a;

    int init = a.getMoney();

    cout << "Uang mula-mula : "<< init << endl;

    while(!a.win()){
        if(a.buyEgg()){
            cout << "Beli telur\n";
        }else{
            cout << "uang kurang, tambah uang dulu\n";
            a.addMoney(1000);
            int n = a.getMoney();
            cout << "Uang saat ini :" << n << endl;
        }
    }
    cout << "Phase egg :" << a.getEgg_Phase() << " selamat Anda menang!" << endl;


    return 0;
}