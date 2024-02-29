#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(){
	Intern bozo;
	AForm *form;

	/*
		form names must be typed like this cause the intern is stupid

		robotomy request
		shrubbery creation
		presidential pardon
	*/
	cout << endl;
	form = bozo.makeForm("robotomy request", "haloo");
	cout << *form << endl;
	delete form;
	cout << endl;
	form = bozo.makeForm("shrubbery creation", "looha");
	cout << *form << endl;
	delete form;
	cout << endl;
	form = bozo.makeForm("presidential pardon", "hoola");
	cout << *form << endl;
	delete form;
	cout << endl;

	try{
		form = bozo.makeForm("president", "obma");
		cout << *form << endl;
		delete form;
	}
	catch(std::exception &e){
		cout << e.what() << endl;
	}
}