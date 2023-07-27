#include "Animal.hpp"
// Orthodox Canonical Class Form
Dog::Dog(){
	cout << "Dogs are here!" << endl;
	setType("Dog");
	brain = new Brain();
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
	delete brain;
}



// Others
void	Dog::makeSound() const{
	cout << "Bork" << endl;
}

string	Dog::getIdeas(int i) const{
	return (brain->getIdeas(i));
}

void	Dog::setIdeas(string set, int i){
	brain->setIdeas(set, i);
}
