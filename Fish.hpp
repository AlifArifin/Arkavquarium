#ifndef FISH_HPP
#define FISH_HPP

#include <iostream>
#include "Summonable.hpp"
#include "Coin.hpp"

using namespace std;

class Fish : public Summonable{
    public:
        /*Sekawan*/
        Fish(int, Point); //constructor jenis value
        ~Fish(); //destructor dibuat untuk animasi mati biar dramatis
        
        /*Getter*/
        bool getHungry() const;
        static int getHunger_Time();
        static int getDead_Time(); 
        double getCount_Move() const;
        double getChange_Move() const;
        int getValue() const;
        static int getSpeed_Fish();

        /*Setter*/
        void setHungry(bool);
        void setCount_Move(double);
        void setChange_Move(); //dilakukan secara random
        
        /*Method*/
        virtual void show() = 0; //untuk makan
        virtual void eat() = 0; //untuk makan 

    protected:
        bool hungry; //status kelaparan Fish
        const static int hunger_time; //periode Fish lapar
        const static int dead_time; //waktu yang dibutuhkan 
        double count_move; //untuk keperluan hunger_time dan dead_time dan coin (khusus guppy)
        double change_move; //untuk keperluan penggantian arah (X Waktu)
        static const int speed_fish; //mencatat kecepatan untuk Fish
        const int value; //harga ikan
};

#endif