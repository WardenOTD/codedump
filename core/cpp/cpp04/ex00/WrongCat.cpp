#include "Animal.hpp"
// Orthodox Canonical Class Form
WrongCat::WrongCat(){
	cout << "No cats here!" << endl;
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &wc){
	cout << "No copycat" << endl;
	*this = wc;
}

WrongCat &WrongCat::operator= (const WrongCat &wc){
	cout << "No cat cloning" << endl;
	if (this != &wc){
		type = wc.type;
	}
	return (*this);
}

WrongCat::~WrongCat(){
	cout << "No cat has passed.." << endl;
}



// Others
void	WrongCat::makeSound() const{
	cout << "Nyan~" << endl;
}
