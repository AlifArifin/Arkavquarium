#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include <iostream>
#include "Fish.hpp"
#include "Coin.hpp"
#include "Guppy.hpp"
#include "ListObj.hpp"
using namespace std;

class Piranha : public Fish{
    public:
        /*Sekawan*/
        Piranha(Point);

        /*Getter*/

        /*Setter*/
        
        /*Method*/
        Guppy move(const ListObj<Guppy>&, const Matrix&); //untuk pergerakkan Piranha    
        void eat(); //untuk dan makan menghasilkan koin
        Coin dropCoin(const Guppy&); //untuk menghasilkan koin      
        void show(); //untuk display piranha
    
    private:
        static const int value_piranha; //harga ikan piranha
};

#endif