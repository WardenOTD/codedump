#include "Animal.hpp"
// Orthodox Canonical Class Form
Brain::Brain(){
	cout << "Brain online" << endl;
	for (int i = 0; i < 100; i++){
		ideas[i].assign("");
	}
}

Brain::Brain(const Brain &b){
	cout << "Brain copy" << endl;
	*this = b;
}

Brain &Brain::operator= (const Brain &b){
	cout << "Brain clone" << endl;
	if (this != &b){
		for (int i = 0; i < 100; i++){
			ideas[i].assign(b.ideas[i]);
	}
	}
	return (*this);
}

Brain::~Brain(){
	cout << "Brain rot" << endl;
}



// Others
string	Brain::getIdeas(int i) const{
	if (i >= 0 && i < 100){
		cout << "Remember" << endl;
		if (!ideas[i].compare("")){
			cout << "Alzheimers plague thee.." << endl;
			return ("");
		}
		return (ideas[i]);
	}
	cout << "Did I ever remember that?" << endl;
	return ("");
}

void	Brain::setIdeas(string set, int i){
	if (i >= 0 && i < 100){
		ideas[i].assign(set);
		cout << "Great idea!" << endl;
	}
	else
		cout << "Brain too small.." << endl;
}
