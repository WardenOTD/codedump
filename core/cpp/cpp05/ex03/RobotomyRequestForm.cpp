#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("Robotomy"){
	cout << "Robotomy" << endl;
	this->setname(target);
	this->setgradeSig(72);
	this->setgradeReq(45);
	this->setSign(false);
}

RobotomyRequestForm::RobotomyRequestForm(string target) : target(target){
	cout << "Robotomy form" << endl;
	this->setname(target);
	this->setgradeSig(72);
	this->setgradeReq(45);
	this->setSign(false);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a){
	cout << "Robotomy clone" << endl;
	this->target = a.target;
	this->setname(target);
	this->setgradeSig(72);
	this->setgradeReq(45);
	this->setSign(false);
}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &a){
	cout << "Robotomy copy" << endl;
	if (this != &a)
		this->target = a.getTarget();
	this->setname(target);
	this->setgradeSig(72);
	this->setgradeReq(45);
	this->setSign(false);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	cout << "Robotomy form burnt" << endl;
}

string	RobotomyRequestForm::getTarget() const{
	return (this->target);
}

void	RobotomyRequestForm::smtg() const{
	srand(time(NULL) + rand());
	cout << "Intense drilling with the feint scream of agony" << endl;
	if (rand() % 2)
		cout << this->getTarget() << " has been robotomized successfully" << endl;
	else
		cout << this->getTarget() << "'s robotomy has failed, we are not held accountable for your loss" << endl;
}

AForm *RobotomyRequestForm::fncPtr(string target){
	AForm *a = new RobotomyRequestForm(target);
	return (a);
}