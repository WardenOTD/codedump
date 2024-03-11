	#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;
class AForm;

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

class IsNotSigned : public std::exception {
	public:
		const char *what() const throw(){
			return ("Form not signed");
		}
};

class AForm {
	public:
		//OCCF
		AForm();
		AForm(string name, int gradeSig, int gradeReq);
		AForm(const AForm &a);
		AForm & operator= (const AForm &a);
		virtual ~AForm();
		//others
		string	getname() const;
		int		getgradeSig() const;
		int		getgradeReq() const;
		bool	getSign() const;
		void	setname(string nam);
		void	setgradeSig(int sig);
		void	setgradeReq(int req);
		void	setSign(bool sig);
		void	beSigned(const Bureaucrat &be);
		void	execute(Bureaucrat const &executor) const;
		virtual void	smtg() const = 0;
	private:
		string	name;
		int		gradeSig;
		int		gradeReq;
		bool	sign;
};

std::ostream & operator<< (std::ostream &out, const AForm &obj);

#endif