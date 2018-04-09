#include "Coin.hpp"

const int coin_speed = 5;

/*Sekawan*/
Coin::Coin(Point P, int _val) : Summonable("coin", coin_speed, P), value(_val) {}

Coin::~Coin() { //destructor sekalian untuk menambah koin pemain
    
}
/*Getter*/

/*Setter*/

/*Method*/
void Coin::move() {} //untuk pergerakkan koin
void Coin::show() {} //untuk menampilkan koin