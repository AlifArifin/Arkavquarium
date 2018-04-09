#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

using namespace std;

class Account{

	private :
		int money;
		const int egg_price;

	public :

		//constructor
		Account();
		//getter
		int getMoney();

		//setter
		void setMoney(int);
		void addMoney(int);
		bool buyGuppy();
		bool buyPiranha();
		bool buyFood();
		bool buyEgg();


};

#endif