#include "Bureaucrat.hpp"

//OCCF
Bureaucrat::Bureaucrat(){
	cout << "Bureaucrat consructed" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &a){
	cout << "Bureaucrat copy constructer" << endl;
	*this = a;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &a){
	cout << "Bureaucrat equal overload" << endl;
	if (this != &a){
		name = a.name;
		grade = a.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	cout << "Bureaucrat destructed" << endl;
}