#include "AForm.hpp"

AForm::AForm() : gradeSig(1), gradeReq(1), sign(false), name("Bureau"){
	cout << "AForm consructed" << endl;
}

AForm::AForm(string name, int gradeSig, int gradeReq) : name(name), gradeSig(gradeSig), gradeReq(gradeReq), sign(false){
	cout << "AForm with params constructed" << endl;
	if (gradeSig < 1 || gradeReq < 1)
		throw (AForm::FormGradeTooHighException);
	if (gradeSig > 150 || gradeReq > 150)
		throw (AForm::FormGradeTooLowException);
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
		throw (AForm::FormGradeTooLowException);
	else{
		if (this->getSign())
			throw (AForm::FormIsSigned);
		this->sign = true;
	}
}

void	AForm::execute(Bureaucrat const &executor){
	if (!this->sign)
		throw (AForm::FormIsNotSigned);
	if (executor.getgrade() > this->getgradeReq())
		throw (AForm::FormGradeTooLowException);
	else
		AForm::smtg();
}