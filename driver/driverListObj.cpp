#include <iostream>
#include "../src/ListObj.hpp"
#include "../src/Guppy.hpp"
#include "../src/Piranha.hpp"
#include "../src/Coin.hpp"
#include "../src/Food.hpp"
#include "../src/Point.hpp"

using namespace std;

int main(){
    ListObj<Guppy> list_guppy;
    ListObj<Piranha> list_piranha;
    ListObj<Coin> list_coin;
    ListObj<Food> list_food;

    Point g1_pos(0, 0);
    Point g2_pos(3, 4);
    Point p1_pos(2, 2);
    Point f1_pos(5, 5);
    Point c1_pos(5, 0);

    Guppy g1(g1_pos);
    Guppy g2(g2_pos);
    //Guppy g3(g1_pos);
    Piranha p1(p1_pos);
    Food f1(f1_pos);
    Coin c1(c1_pos, 100);

    list_guppy.add(g1);
    list_guppy.add(g2);
    list_piranha.add(p1);
    list_food.add(f1);
    list_coin.add(c1);

    int len_guppy = list_guppy.size();
    int len_piranha = list_piranha.size();
    int len_food = list_food.size();
    int len_coin = list_coin.size();

    cout << "banyak guppy tersisa : " << len_guppy << endl;
    cout << "banyak piranha tersisa : " << len_piranha << endl;
    cout << "banyak makanan tersisa : " << len_food << endl;
    cout << "banyak koin tersisa : " << len_coin << endl;

    int idfound = list_guppy.find(g2);
    cout << "guppy ditemukan pada indeks ke-" << idfound << endl;

    Guppy g3 = list_guppy.removeIdx(idfound);
    
    cout << "Guppy dihapus" << endl;

    //cout << " guppy pada lokasi " << g3.getPosition.getX() << " dan" << g3.getPosition.getY() << " telah dihapus ! "<< endl;

    len_guppy = list_guppy.size();
    if(list_guppy.isEmpty()){
        cout << "kosong" << endl;
    }else{
        cout << "masih ada "<< len_guppy << " elemen !" << endl;
    }     

    return 0;
}