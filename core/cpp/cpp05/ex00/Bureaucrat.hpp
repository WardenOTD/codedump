#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class Bureaucrat {
	public:
		//OCCF
		Bureaucrat();
		Bureaucrat(const Bureaucrat &a);
		Bureaucrat & operator= (const Bureaucrat &a);
		~Bureaucrat();
	private:
		string	name;
		int		grade;
};

#endif