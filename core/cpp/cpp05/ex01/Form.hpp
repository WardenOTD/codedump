#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;
class Form;

class GradeTooHighForm : public std::exception {
	public:
		const char *what() const throw(){
			return ("Grade Too High");
		}
};

class GradeTooLowForm : public std::exception {
	public:
		const char *what() const throw(){
			return ("Grade Too Low");
		}
};

class IsSigned : public std::exception {
	public:
		const char *what() const throw(){
			return ("Form already signed");
		}
};

class Form {
	public:
		//OCCF
		Form();
		Form(string name, int gradeSig, int gradeReq);
		Form(const Form &a);
		Form & operator= (const Form &a);
		~Form();
		//others
		string	getname() const;
		int		getgradeSig() const;
		int		getgradeReq() const;
		bool	getSign() const;
		void	beSigned(const Bureaucrat &be);
	private:
		string	name;
		int		gradeSig;
		int		gradeReq;
		bool	sign;
};

std::ostream & operator<< (std::ostream &out, const Form &obj);

#endif