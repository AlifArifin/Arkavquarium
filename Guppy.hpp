#ifndef GUPPY_HPP
#define GUPPY_HPP

#include <iostream>
#include "Fish.hpp"
#include "ListObj.hpp"
#include "Food.hpp"
using namespace std;

class Guppy : public Fish{
    public:
        /*Sekawan*/
        Guppy(Point);

        /*Getter*/
        int getPhase() const;
        int getCoin_Time() const;
        int getFood_Count() const;

        /*Setter*/
        void setPhase(int);
        void setFood_Count(int);
        
        /*Method*/
        int move(const ListObj<Food>&, const Matrix&); //untuk pergerakkan Guppy    
        Coin dropCoin(); //untuk menghasilkan koin
        void eat(); //untuk makan
        void show(); //untuk display guppy
    
    private:
        int phase; //tahap dari guppy 
        int food_count; //menghitung banyaknya makanan yang telah dimakan
        const static int coin_time; //periode mengeluarkan koin
        const static int value_guppy;   //harga guppy
        const static int value_coin; //value coin yang dihasilkan guppy
};

#endif