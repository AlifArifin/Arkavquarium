#include "Coin.hpp"

class Coin : public Summonable {
    public:
        /*Sekawan*/
        Coin();
        ~Coin(); //destructor sekalian untuk menambah koin pemain

        /*Getter*/

        /*Setter*/

        /*Method*/
        void move(); //untuk pergerakkan koin
        void show(); //untuk menampilkan koin
    
    private:
        const int value;
};

#endif