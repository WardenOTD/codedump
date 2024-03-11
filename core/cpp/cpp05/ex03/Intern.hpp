#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class InvalidForm : public std::exception{
	public:
		const char *what() const throw(){
			return ("Form does not exist");
		}

};

class Intern{
	public:
		//occf
		Intern();
		Intern(const Intern &a);
		Intern & operator=(const Intern &a);
		~Intern();
		//others
		AForm	*makeForm(string name, string target);
	private:
		string		forms[3];
};

#endif