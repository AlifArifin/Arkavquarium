#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

using namespace std;

class Account{

	private :
		static int money;
		static const int egg_price;
		int egg_phase;

	public :

		//constructor
		Account();
		
		//getter
		static int getMoney();

		//setter
		static void setMoney(int);
		
		//method
		static void addMoney(int);
		bool win();
		bool buyGuppy();
		bool buyPiranha();
		bool buyFood();
		bool buyEgg();
};

#endif