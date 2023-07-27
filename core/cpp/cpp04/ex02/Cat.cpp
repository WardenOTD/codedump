#include "Animal.hpp"
// Orthodox Canonical Class Form
Cat::Cat(){
	cout << "Cats are here!" << endl;
	setType("Cat");
	brain = new Brain();
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
	delete brain;
}



// Others
void	Cat::makeSound() const{
	cout << "Nyan~" << endl;
}

string	Cat::getIdeas(int i) const{
	return (brain->getIdeas(i));
}

void	Cat::setIdeas(string set, int i){
	brain->setIdeas(set, i);
}
