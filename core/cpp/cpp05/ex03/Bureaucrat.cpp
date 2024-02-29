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
		throw (Bureaucrat::GradeTooHighException);
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException);
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
		throw (Bureaucrat::GradeTooHighException);
	}
}

void Bureaucrat::decrement() {
	++this->grade;
	if (this->grade > 150)
	{
		delete this;
		throw (Bureaucrat::GradeTooLowException);
	}
}

std::ostream & operator<< (std::ostream &out, const Bureaucrat &obj){
	return (out << "わがなわ " << obj.getname() << ", bureaucrat grade " << obj.getgrade() << ".");
}

void Bureaucrat::signForm(const Bureaucrat &be, AForm &fo){
	if (be.getgrade() > fo.getgradeSig()){
		cout << be.getname() << " couldn't sign " << fo.getname();
		cout << " because " << be.getname() << "'s grade is too low." << endl;
		cout << be.getname() << ": " << be.getgrade() << endl;
		cout << "Grade of " << fo.getgradeSig() << " required." << endl;
		fo.beSigned(be);
	}
	else{
		fo.beSigned(be);
		cout << be.getname() << " signed " << fo.getname() << endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form){
	try{
		form.execute(*this);
	}
	catch(std::exception &e){
		cout << name << " failed to execute " << form.getname() << " because " << e.what() << endl;
		return ;
	}
	cout << name << " successfully executed " << form.getname() << endl;
}