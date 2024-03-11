#include "Bureaucrat.hpp"

//OCCF
Bureaucrat::Bureaucrat(){
	cout << "Bureaucrat consructed" << endl;
	this->grade = 1;
	this->name = "Bureau";
}

Bureaucrat::Bureaucrat(string name, int grade) : name(name) {
	cout << "Bureaucrat with params constructed" << endl;
	if (grade < 1)
		throw (GradeTooHigh());
	if (grade > 150)
		throw (GradeTooLow());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &a){
	cout << "Bureaucrat copy constructer" << endl;
	*this = a;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &a){
	cout << "Bureaucrat equal overload" << endl;
	if (this != &a){
		this->name = a.getname();
		this->grade = a.getgrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	cout << "Bureaucrat destructed" << endl;
}

//other stuff
string	Bureaucrat::getname() const{
	return (this->name);
}

int	Bureaucrat::getgrade() const{
	return (this->grade);
}

void Bureaucrat::increment() {
	--this->grade;
	if (this->grade < 1)
	{
		delete this;
		throw (GradeTooHigh());
	}
}

void Bureaucrat::decrement() {
	++this->grade;
	if (this->grade > 150)
	{
		delete this;
		throw (GradeTooLow());
	}
}

std::ostream & operator<< (std::ostream &out, const Bureaucrat &obj){
	return (out << "わがなわ " << obj.getname() << ", bureaucrat grade " << obj.getgrade() << ".");
}