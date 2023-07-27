#include "Animal.hpp"
// Orthodox Canonical Class Form
Dog::Dog(){
	cout << "Dogs are here!" << endl;
	setType("Dog");
}

Dog::Dog(const Dog &d){
	cout << "Dog copy" << endl;
	*this = d;
}

Dog &Dog::operator= (const Dog &d){
	cout << "Dog cloning" << endl;
	if (this != &d){
		type = d.type;
	}
	return (*this);
}

Dog::~Dog(){
	cout << "Dog has passed.." << endl;
}



// Others
void	Dog::makeSound() const{
	cout << "Bork" << endl;
}
