#include "Animal.hpp"

int main()
{
// ex00 tests;
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// const WrongAnimal* h = new WrongCat();

	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// cout << h->getType() << " " << endl;

	// i->makeSound();
	// j->makeSound();
	// h->makeSound();
	// meta->makeSound();

	// delete meta;
	// delete j;
	// delete i;
	// delete h;


// ex01 tests-1;
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	// delete j;
	// delete i;

	// const Animal* arr[20];
	// for (int p = 0; p < 20; p++)
	// {
	// 	if (p < 10)
	// 		arr[p] = new Dog();
	// 	if (p > 10)
	// 		arr[p] = new Cat();
	// }

	// for (int p = 0; p < 20; p++)
	// 	delete arr[p];


// ex01 tests-2;
	Dog dog;
	Cat cat;
	cout << dog.getIdeas(0);
	cout << cat.getIdeas(0);

	cat.setIdeas("cr", 0);
	Cat cat2(cat);
	cout << endl << "cat: " << cat.getIdeas(0);
	cout << endl << "cat2: " << cat2.getIdeas(0);
	cat2.setIdeas("cc", 0);
	cout << endl << "cat: " << cat.getIdeas(0);
	cout << endl << "cat2: " << cat2.getIdeas(0);
	cout << endl << "cat: " << &cat << endl << "cat2: " << &cat2 << endl;
	system("leaks animal");
	exit(0);


	for (int p = 0; p < 100; p++)
	{
		dog.setIdeas("food", p);
		cat.setIdeas("food", p);
	}

	dog.setIdeas("food?", 100);
	cat.setIdeas("food?", 100);

	for (int p = 0; p < 100; p++)
	{
		cout << dog.getIdeas(p);
		cout << cat.getIdeas(p);
	}

	cout << dog.getIdeas(100);
	cout << cat.getIdeas(100);


	system("leaks animal");
	return 0;
}
