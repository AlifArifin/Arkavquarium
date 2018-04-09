#include "Account.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include "Food.hpp"

int money = 0;
const int egg_price = 1000;

//constructor
Account::Account() {
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
    money = money + val;
}
<<<<<<< HEAD
bool Account::buyGuppy() {}
bool Account::buyPiranha() {}
=======

bool Account::buyGuppy() {
    return money >= Guppy::getValue_Guppy();
}

bool Account::buyPiranha() {
    return money >= Piranha::getValue_Piranha();
}

>>>>>>> 3c8d1a1f1705f30d44f17397ab0a406eb583ddca
bool Account::buyFood() {}

bool Account::buyEgg() {
    return money >= egg_price;
}
