#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){
	cout << "Intern hired" << endl;
	forms[0] = "robotomy request";
	forms[1] = "shrubbery creation";
	forms[2] = "presidential pardon";
}

Intern::Intern(const Intern &a){
	cout << "Intern stolen" << endl;
	this->forms[0] = a.forms[0];
	this->forms[1] = a.forms[1];
	this->forms[2] = a.forms[2];
}

Intern &Intern::operator=(const Intern &a){
	cout << "Intern cloned" << endl;
	this->forms[0] = a.forms[0];
	this->forms[1] = a.forms[1];
	this->forms[2] = a.forms[2];
	return (*this);
}

Intern::~Intern(){
	cout << "Intern fired" << endl;
}

AForm	*Intern::makeForm(string name, string target){
	AForm *(*funcptr[3])(string) = {
		RobotomyRequestForm::fncPtr,
		ShrubberyCreationForm::fncPtr,
		PresidentialPardonForm::fncPtr
		};
	AForm *a = NULL;
	int	c = 0;
	for (int i = 0; i < 3; i++)
	{
		if (!forms[i].compare(name)){
			a = funcptr[i](target);
			break ;
		}
		c++;
		if (c == 3)
			throw (InvalidForm());
	}
	return (a);
}