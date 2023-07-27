#include "Animal.hpp"
// Orthodox Canonical Class Form
Cat::Cat(){
	cout << "Cats are here!" << endl;
	setType("Cat");
}

Cat::Cat(const Cat &c){
	cout << "Copycat" << endl;
	*this = c;
}

Cat &Cat::operator= (const Cat &c){
	cout << "Cat cloning" << endl;
	if (this != &c){
		type = c.type;
	}
	return (*this);
}

Cat::~Cat(){
	cout << "Cat has passed.." << endl;
}



// Others
void	Cat::makeSound() const{
	cout << "Nyan~" << endl;
}
