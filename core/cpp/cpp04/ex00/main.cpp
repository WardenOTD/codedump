#include "Animal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* h = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	cout << h->getType() << " " << endl;

	i->makeSound();
	j->makeSound();
	h->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete h;
	return 0;
}
