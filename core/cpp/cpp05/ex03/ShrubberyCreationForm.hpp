#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

using std::string;
using std::cout;
using std::endl;

class ShrubberyCreationForm : public AForm{
	public:
		//OCCF
		ShrubberyCreationForm();
		ShrubberyCreationForm(string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &a);
		ShrubberyCreationForm & operator= (const ShrubberyCreationForm &a);
		~ShrubberyCreationForm();
		//others
		string	getTarget() const;
		void	smtg() const;
		static AForm *fncPtr(string target);
	private:
		string target;
};

#endif