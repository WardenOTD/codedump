#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;
class Form;

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
		void	signForm(const Bureaucrat &be, Form &fo);
	private:
		string	name;
		int		grade;
};

std::ostream & operator<< (std::ostream &out, const Bureaucrat &obj);

#endif