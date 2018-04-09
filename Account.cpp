#include "Account.hpp"

// private :
// 	int money;


//constructor
Account::Account() : egg_price(1000) {
    money = 0;
}
//getter
int Account::getMoney() {
    return money;
}

//setter
void Account::setMoney(int _money) {
    money = _money;
}

void Account::addMoney(int val) {
    money += val;
}
bool Account::buyGuppy() {}
bool Account::buyPiranha() {}
bool Account::buyFood() {}
bool Account::buyEgg() {}
