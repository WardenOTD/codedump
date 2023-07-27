#include "Animal.hpp"
// Orthodox Canonical Class Form
Animal::Animal(){
	cout << "Animals exist" << endl;
	setType("The Animal");
}

Animal::Animal(const Animal &a){
	cout << "Animal copy" << endl;
	*this = a;
}

Animal &Animal::operator= (const Animal &a){
	cout << "Animal cloning" << endl;
	if (this != &a){
		type = a.type;
	}
	return (*this);
}

Animal::~Animal(){
	cout << "All animals die eventually.." << endl;
}



// Others
string	Animal::getType() const{
	return (type);
}

void	Animal::setType(string set){
	type = set;
}

void	Animal::makeSound() const{
	cout << "Conglomerate of random animal noises" << endl;
}



/*-------Wrong Animal-------*/
// Orthodox Canonical Class Form
WrongAnimal::WrongAnimal(){
	cout << "Animals don't exist" << endl;
	setType("Not The Animal");
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa){
	cout << "Not Animal copy" << endl;
	*this = wa;
}

WrongAnimal &WrongAnimal::operator= (const WrongAnimal &wa){
	cout << "Not Animal cloning" << endl;
	if (this != &wa){
		type = wa.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	cout << "Not all animals die eventually.." << endl;
}



// Others
string	WrongAnimal::getType() const{
	return (type);
}

void	WrongAnimal::setType(string set){
	type = set;
}

void	WrongAnimal::makeSound() const{
	cout << "The Screech of What Could Only be Described as an Eldritch Horror" << endl;
}
