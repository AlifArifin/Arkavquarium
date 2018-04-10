#include "Account.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include "Food.hpp"

int Account::money = 0;
const int Account::egg_price = 1000;

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

bool Account::buyGuppy() {
    return money >= Guppy::getValue_Guppy();
}

bool Account::buyPiranha() {
    return money >= Piranha::getValue_Piranha();
}

bool Account::buyFood() {
    return money >= Food::getValue_Food();
}

bool Account::buyEgg() {
    return money >= egg_price;
}
