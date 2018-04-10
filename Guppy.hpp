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
        static int getCoin_Time();
        int getFood_Count() const;
        static int getValue_Guppy();
        static int getRadius_Guppy();

        /*Setter*/
        void setPhase(int);
        void setFood_Count(int);
        
        /*Method*/
        int move(const ListObj<Food>&, const Matrix&, double); //untuk pergerakkan Guppy    
        Coin dropCoin(); //untuk menghasilkan koin
        void eat(); //untuk makan
        void show(); //untuk display guppy
        bool operator==(const Guppy&) const;
    
    private:
        int phase; //tahap dari guppy 
        int food_count; //menghitung banyaknya makanan yang telah dimakan
        const static int coin_time; //periode mengeluarkan koin
        const static int value_guppy;   //harga guppy
        const static int value_coin; //value coin yang dihasilkan guppy
        const static int grow_time;
        const static int radius_guppy;
};

#endif