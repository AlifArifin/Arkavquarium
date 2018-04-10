#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "Guppy.hpp"
#include "Piranha.hpp"
#include "Snail.hpp"
#include "Coin.hpp"
#include "Food.hpp"
#include "ListObj.hpp"
#include "Matrix.hpp"
#include "Account.hpp"
#include <iostream>

using namespace std;

class Aquarium {
    public:
        /*Sekawan*/
        Aquarium();

        /*Getter*/
        ListObj<Guppy> getList_Guppy() const;
        ListObj<Piranha> getList_Piranha() const;
        ListObj<Food> getList_Food() const;
        ListObj<Snail> getList_Snail() const;
        ListObj<Coin> getList_Coin() const;
        Matrix getAquarium_Matrix() const;

        /*Setter*/
        void setList_Guppy(ListObj<Guppy>&);
        void setList_Piranha(ListObj<Piranha>&);
        void setList_Food(ListObj<Food>&);
        void setList_Snail(ListObj<Snail>&);
        void setList_Coin(ListObj<Coin>&);
        //void setAquarium_Matrix(Matrix&)''

        /*Method*/
        void add(const Guppy&); //menambahkan Guppy ke dalam aquarium
        void add(const Piranha&); //menambahkan Piranha ke dalam aquarium
        void add(const Snail&); //menambahkan Snail ke dalam aquarium
        void add(const Coin&); //menambahkan Coin ke dalam aquarium
        void add(const Food&); //menambahkan Food ke dalam aquarium
        void del(Guppy&); //menghapus Guppy dari dalam aquarium
        void del(Piranha&); //menghapus Piranha dari dalam aquarium
        void del(Snail&); //menghapus Snail dari dalam aquarium
        void del(Coin&); //menghapus Coin dari dalam aquarium
        void del(Food&); //menghapus Food dari dalam aquarium
        void showAll(); //menampilkan semua summonable yang ada pada aquarium
        void moveAll(double); //menggerakkan semua summonable yang ada pada aquarium

    private:
        ListObj<Guppy> list_guppy; //list menyimpan Guppy yang ada di dalam aquarium
        ListObj<Piranha> list_piranha; //list menyimpan Piranha yang ada di dalam aquarium
        ListObj<Snail> list_snail; //list menyimpan Snail yang ada di dalam aquarium
        ListObj<Coin> list_coin; //list menyimpan Coin yang ada di dalam aquarium
        ListObj<Food> list_food; //list menyimpan Food yang ada di dalam aquarium
        Matrix aquarium_matrix; //Matriks aquarium;
        Account player;
};

#endif

        