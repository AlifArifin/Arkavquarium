#ifndef FISH_HPP
#define FISH_HPP

#include <iostream>
#include "Summonable.hpp"
#include "Coin.hpp"

using namespace std;

class Fish : public Summonable{
    public:
        /*Sekawan*/
        Fish(string, int, Point); //constructor jenis value
        ~Fish(); //destructor dibuat untuk animasi mati biar dramatis
        
        /*Getter*/
        bool getHungry() const;
        int getFood_Count() const;
        static int getHunger_Time();
        static int getDead_Time(); 
        int getCount_Move() const;
        int getChange_Move() const;
        int getValue() const;
        static int getSpeed_Fish();

        /*Setter*/
        void setHungry(bool);
        void setFood_Count(int);
        void setCount_Move(int);
        void setChange_Move(); //dilakukan secara random
        
        /*Method*/
        virtual void eat() = 0; //untuk makan

    protected:
        bool hungry; //status kelaparan Fish
        int food_count; //menghitung banyaknya makanan yang telah dimakan
        const static int hunger_time; //periode Fish lapar
        const static int dead_time; //waktu yang dibutuhkan 
        int count_move; //untuk keperluan hunger_time dan dead_time dan coin (khusus guppy)
        int change_move; //untuk keperluan penggantian arah (X Waktu)
        static const int speed_fish; //mencatat kecepatan untuk Fish
        const int value; //harga ikan
};

#endif