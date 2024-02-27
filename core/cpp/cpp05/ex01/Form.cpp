#include "Form.hpp"

Form::Form(){
	cout << "Form consructed" << endl;
	this->gradeSig = 1;
	this->gradeReq = 1;
	this->sign = false;
	this->name = "Bureau";
}

Form::Form(string name, int gradeSig, int gradeReq) : name(name) {
	cout << "Form with params constructed" << endl;
	if (gradeSig < 1 || gradeReq < 1)
		throw (Form::FormGradeTooHighException);
	if (gradeSig > 150 || gradeReq > 150)
		throw (Form::FormGradeTooLowException);
	this->gradeSig = gradeSig;
	this->gradeReq = gradeReq;
	this->sign = false;
}

Form::Form(const Form &a){
	cout << "Form copy constructer" << endl;
	*this = a;
}

Form &Form::operator= (const Form &a){
	cout << "Form equal overload" << endl;
	if (this != &a){
		this->name = a.getname();
		this->gradeSig = a.getgradeSig();
		this->gradeReq = a.getgradeReq();
		this->sign = a.getSign();
	}
	return (*this);
}

Form::~Form(){
	cout << "Form destructed" << endl;
}

string Form::getname() const{
	return (this->name);
}

int	Form::getgradeSig() const{
	return (this->gradeSig);
}

int	Form::getgradeReq() const{
	return (this->gradeReq);
}

bool Form::getSign() const{
	return (this->sign);
}

std::ostream & operator<< (std::ostream &out, const Form &obj){
	out << "Form " << obj.getname() << ".";
	if (obj.getSign() == true)
		out << " Signed." << endl;
	else
		out << " Unsigned." << endl;
	out << "Grade to sign: " << obj.getgradeSig() << endl;
	return (out << "Grade to execute: " << obj.getgradeReq());
}

void Form::beSigned(const Bureaucrat &be){
	if (be.getgrade() > this->getgradeSig())
		throw (Form::FormGradeTooLowException);
	else{
		if (this->getSign())
			throw (Form::FormIsSigned);
		this->sign = true;
	}
}
