#include "Account.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include "Food.hpp"
#include "oop.hpp"

int Account::money = 20000;
const int Account::egg_price = 1000;
int Account::egg_phase = 0;

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
    if (money >= Guppy::getValue_Guppy()) {
        money -= Guppy::getValue_Guppy();        
        return true;
    } else {
        return false;
    }
}

bool Account::buyPiranha() {
    if (money >= Piranha::getValue_Piranha()) {
        money -= Piranha::getValue_Piranha();
        return true;
    } else {
        return false;
    }
}

bool Account::buyFood() {
    if (money >= Food::getValue_Food()) {
        money -= Food::getValue_Food();
        return true;
    } else {
        return false;
    }
}

bool Account::buyEgg() {
    if (money >= egg_price) {
        money -= egg_price;
        egg_phase = egg_phase + 1;
        return true;
    } else {
        return false;
    }
}

bool Account::win() {
    return egg_phase >= 3;
}

int Account::getEgg_Phase() {
    return egg_phase;
}