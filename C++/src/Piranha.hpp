#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include <iostream>
#include "Fish.hpp"
#include "Coin.hpp"
#include "Guppy.hpp"
#include "ListObj.hpp"
#include "Matrix.hpp"
using namespace std;

class Piranha : public Fish{
    public:
        /*Sekawan*/
        Piranha(Point);

        /*Getter*/
        static int getValue_Piranha();
        static int getRadius_Piranha();
        string getImage();

        /*Setter*/
        void setDirection(int);

        /*Method*/
        int move(const ListObj<Guppy>&, const Matrix&, double); //untuk pergerakkan Piranha    
        void eat(); //untuk dan makan menghasilkan koin
        Coin dropCoin(const Guppy&); //untuk menghasilkan koin      
        bool operator==(const Piranha&) const;
    private:
        static const int value_piranha; //harga ikan piranha
        static const int radius_piranha;
        static const string image_piranha[4];
        string image;
};

#endif