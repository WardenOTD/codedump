#include "Serializer.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(){
	Data wow;
	wow.item = 1;
	wow.itemc = 'X';
	wow.items[0] = 'H';
	wow.items[1] = 'e';
	wow.items[2] = 'l';
	wow.items[3] = 'l';
	wow.items[4] = 'o';
	wow.items[5] = 0;
	cout << wow.item << endl << wow.itemc << endl << wow.items << endl << &wow << endl;

	uintptr_t cereal = Serializer::serialize(&wow);
	cout << cereal << endl;
	Data *woah = Serializer::deserialize(cereal);
	cout << woah->item << endl << woah->itemc << endl << woah->items << endl << woah << endl;
}
