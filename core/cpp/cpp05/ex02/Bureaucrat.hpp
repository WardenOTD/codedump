#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;
class AForm;

class GradeTooHigh : public std::exception {
	public:
		const char *what() const throw(){
			return ("Grade Too High");
		}
};

class GradeTooLow : public std::exception {
	public:
		const char *what() const throw(){
			return ("Grade Too Low");
		}
};

class Bureaucrat {
	public:
		//OCCF
		Bureaucrat();
		Bureaucrat(string name, int grade);
		Bureaucrat(const Bureaucrat &a);
		Bureaucrat & operator= (const Bureaucrat &a);
		~Bureaucrat();
		//others
		string	getname() const;
		int		getgrade() const;
		void	increment();
		void	decrement();
		void	signForm(const Bureaucrat &be, AForm &fo);
		void	executeForm(AForm const & form);
	private:
		string	name;
		int		grade;
		GradeTooHigh GradeTooHighException;
		GradeTooLow GradeTooLowException;
};

std::ostream & operator<< (std::ostream &out, const Bureaucrat &obj);

#endif