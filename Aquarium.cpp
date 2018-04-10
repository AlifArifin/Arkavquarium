#include "Aquarium.hpp"
using namespace std;

Aquarium::Aquarium(){}

ListObj<Guppy> Aquarium::getList_Guppy() const{return list_guppy;}
ListObj<Piranha> Aquarium::getList_Piranha() const{return list_piranha;}
ListObj<Food> Aquarium::getList_Food() const{return list_food;}
ListObj<Snail> Aquarium::getList_Snail() const{return list_snail;}
ListObj<Coin> Aquarium::getList_Coin() const{return list_coin;}
Matrix Aquarium::getAquarium_Matrix() const{return aquarium_matrix;}

void Aquarium::setList_Guppy(ListObj<Guppy> &newlist){list_guppy=newlist;}
void Aquarium::setList_Piranha(ListObj<Piranha> &newlist){list_piranha=newlist;}
void Aquarium::setList_Food(ListObj<Food> &newlist){list_food=newlist;}
void Aquarium::setList_Snail(ListObj<Snail> &newlist){list_snail=newlist;}
void Aquarium::setList_Coin(ListObj<Coin> &newlist){list_coin=newlist;}
//void Aquarium::setAquarium_Matrix(Matrix &newmatrix){aquarium_matrix=newmatrix;}

void Aquarium::add(const Guppy &newguppy){list_guppy.add(newguppy);} //menambahkan Guppy ke dalam aquarium
void Aquarium::add(const Piranha &newpiranha){list_piranha.add(newpiranha);} //menambahkan Piranha ke dalam aquarium
void Aquarium::add(const Snail &newsnail){list_snail.add(newsnail);} //menambahkan Snail ke dalam aquarium
void Aquarium::add(const Coin &newcoin){list_coin.add(newcoin);} //menambahkan Coin ke dalam aquarium
void Aquarium::add(const Food &newfood){list_food.add(newfood);} //menambahkan Food ke dalam aquarium
void Aquarium::del(Guppy &guppy){list_guppy.remove(guppy);} //menghapus Guppy dari dalam aquarium
void Aquarium::del(Piranha &piranha){list_piranha.remove(piranha);} //menghapus Piranha dari dalam aquarium
void Aquarium::del(Snail &snail){list_snail.remove(snail);} //menghapus Snail dari dalam aquarium
void Aquarium::del(Coin &coin){list_coin.remove(coin);} //menghapus Coin dari dalam aquarium
void Aquarium::del(Food &food){list_food.remove(food);} //menghapus Food dari dalam aquarium
void Aquarium::showAll(){
	for(int i=0; i<list_guppy.size();i++){
		list_guppy.get(i).show();
	}
	for(int i=0; i<list_piranha.size();i++){
		list_piranha.get(i).show();
	}
	for(int i=0; i<list_food.size();i++){
		list_food.get(i).show();
	}
	for(int i=0; i<list_snail.size();i++){
		list_snail.get(i).show();
	}
	for(int i=0; i<list_coin.size();i++){
		list_coin.get(i).show();
	}
}//menampilkan semua summonable yang ada pada aquarium ??GIMANA
void Aquarium::moveAll(double time){
	
	for (int i = 0; i < list_food.size(); i++) {
		bool bottom = list_food.get(i).move(aquarium_matrix, time);

		if (bottom) {
			Food f = list_food.removeIdx(i);

			f.~Food();
			
			i--;
		}
	}
	
	for (int i = 0; i < list_guppy.size(); i++) {
		int idx = list_guppy.get(i).move(list_food, aquarium_matrix, time);

		if (idx == -2) {
			Guppy g = list_guppy.removeIdx(i);

			g.~Guppy();
			i--;
		} else if (idx != -1) {
			Food f = list_food.removeIdx(idx);

			list_guppy.get(i).eat();

			f.~Food();
		}
	}
	
	for (int i = 0; i < list_piranha.size(); i++) {
		int idx = list_piranha.get(i).move(list_guppy, aquarium_matrix, time);

		if (idx != -1) {
			Guppy g = list_guppy.removeIdx(idx);

			list_piranha.get(i).eat();
			Coin c = list_piranha.get(i).dropCoin(g);

			list_coin.add(c);

			g.~Guppy();
		}
	}
	
	for (int i = 0; i < list_coin.size(); i++) {
		list_coin.get(i).move(aquarium_matrix, time);
	}

	for (int i = 0; i < list_snail.size(); i++) {
		int idx = list_snail.get(i).move(list_coin, time);

		if (idx != -1) {
			Coin c = list_coin.removeIdx(idx);

			c.~Coin();
		}
	}
} //menggerakkan semua summonable yang ada pada aquarium ??GIMANA

