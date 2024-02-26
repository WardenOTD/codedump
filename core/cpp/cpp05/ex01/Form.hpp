#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

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
		void	beSigned();
		void	signForm();
	private:
		string	name;
		int		gradeSig;
		int		gradeReq;
		bool	sign;
		GradeTooHighForm GradeTooHighException;
		GradeTooLowForm GradeTooLowException;
};

std::ostream & operator<< (std::ostream &out, const Form &obj);

#endif