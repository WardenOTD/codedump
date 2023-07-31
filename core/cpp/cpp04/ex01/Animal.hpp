#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class Animal {
	public:
		// Orthodox Canonical Class Form
		Animal();
		Animal(const Animal &a);
		Animal & operator= (const Animal &a);
		virtual ~Animal();

		// Others
		string	getType() const;
		void	setType(string set);
		virtual void	makeSound() const = 0;
	protected:
		string	type;
};

class Brain {
	public:
		// Orthodox Canonical Class Form
		Brain();
		Brain(const Brain &b);
		Brain & operator= (const Brain &b);
		~Brain();

		// Others
		string	getIdeas(int i) const;
		void	setIdeas(string set, int i);
	private:
		string	ideas[100];
};

class Dog : public Animal {
	public:
		// Orthodox Canonical Class Form
		Dog();
		Dog(const Dog &d);
		Dog & operator= (const Dog &d);
		~Dog();

		// Others
		void	makeSound() const;
		string	getIdeas(int i) const;
		void	setIdeas(string set, int i);
	private:
		Brain *brain;
};

class Cat : public Animal {
	public:
		// Orthodox Canonical Class Form
		Cat();
		Cat(const Cat &c);
		Cat & operator= (const Cat &c);
		~Cat();

		// Others
		void	makeSound() const;
		string	getIdeas(int i) const;
		void	setIdeas(string set, int i);
	private:
		Brain *brain;
};




/*--------Wrong---------*/
class WrongAnimal {
	public:
		// Orthodox Canonical Class Form
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wa);
		WrongAnimal & operator= (const WrongAnimal &wa);
		~WrongAnimal();

		// Others
		string	getType() const;
		void	setType(string set);
		void	makeSound() const;
	protected:
		string	type;
};

class WrongCat : public WrongAnimal {
	public:
		// Orthodox Canonical Class Form
		WrongCat();
		WrongCat(const WrongCat &wc);
		WrongCat & operator= (const WrongCat &wc);
		~WrongCat();

		// Others
		void	makeSound() const;
};

#endif
