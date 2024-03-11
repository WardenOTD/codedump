#include "AForm.hpp"

AForm::AForm() : name("Bureau"), gradeSig(1), gradeReq(1), sign(false){
	cout << "AForm consructed" << endl;
}

AForm::AForm(string name, int gradeSig, int gradeReq) : name(name), gradeSig(gradeSig), gradeReq(gradeReq), sign(false){
	cout << "AForm with params constructed" << endl;
	if (gradeSig < 1 || gradeReq < 1)
		throw (GradeTooHighForm());
	if (gradeSig > 150 || gradeReq > 150)
		throw (GradeTooLowForm());
}

AForm::AForm(const AForm &a) : name(a.name), gradeSig(a.gradeSig), gradeReq(a.gradeReq), sign(a.sign){
	cout << "AForm copy constructer" << endl;
}

AForm &AForm::operator= (const AForm &a){
	cout << "AForm equal overload" << endl;
	if (this != &a){
		this->name = a.getname();
		this->gradeSig = a.getgradeSig();
		this->gradeReq = a.getgradeReq();
		this->sign = a.getSign();
	}
	return (*this);
}

AForm::~AForm(){
	cout << "AForm destructed" << endl;
}

string AForm::getname() const{
	return (this->name);
}

int	AForm::getgradeSig() const{
	return (this->gradeSig);
}

int	AForm::getgradeReq() const{
	return (this->gradeReq);
}

bool AForm::getSign() const{
	return (this->sign);
}

void AForm::setname(string nam){
	this->name = nam;
}

void	AForm::setgradeSig(int sig){
	this->gradeSig = sig;
}

void	AForm::setgradeReq(int req){
	this->gradeReq = req;
}

void AForm::setSign(bool sig){
	this->sign = sig;
}

std::ostream & operator<< (std::ostream &out, const AForm &obj){
	out << "Form " << obj.getname() << ".";
	if (obj.getSign() == true)
		out << " Signed." << endl;
	else
		out << " Unsigned." << endl;
	out << "Grade to sign: " << obj.getgradeSig() << endl;
	return (out << "Grade to execute: " << obj.getgradeReq());
}

void AForm::beSigned(const Bureaucrat &be){
	if (be.getgrade() > this->getgradeSig())
		throw (GradeTooLowForm());
	else{
		if (this->getSign())
			throw (IsSigned());
		this->sign = true;
	}
}

void	AForm::execute(Bureaucrat const &executor) const{
	if (!this->sign)
		throw (IsNotSigned());
	if (executor.getgrade() > this->getgradeReq())
		throw (GradeTooLowForm());
	else
		this->smtg();
}