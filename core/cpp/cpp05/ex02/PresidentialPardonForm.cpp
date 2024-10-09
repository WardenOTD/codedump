#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : target("me"){
	cout << "President elected" << endl;
	this->setname(target);
	this->setgradeSig(25);
	this->setgradeReq(5);
	this->setSign(false);
}

PresidentialPardonForm::PresidentialPardonForm(string target) : target(target){
	cout << "President that exists elected" << endl;
	this->setname(target);
	this->setgradeSig(25);
	this->setgradeReq(5);
	this->setSign(false);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : AForm(a){
	cout << "President stand in" << endl;
	this->target = a.target;
	this->setname(target);
	this->setgradeSig(25);
	this->setgradeReq(5);
	this->setSign(false);
}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &a){
	cout << "president twin sibling" << endl;
	if (this != &a)
		this->target = a.getTarget();
	this->setname(target);
	this->setgradeSig(25);
	this->setgradeReq(5);
	this->setSign(false);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	cout << "President died" << endl;
}

string	PresidentialPardonForm::getTarget() const{
	return (this->target);
}

void	PresidentialPardonForm::smtg() const{
	cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << endl;
}
