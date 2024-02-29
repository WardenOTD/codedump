#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class PresidentialPardonForm : public AForm{
	public:
		//OCCF
		PresidentialPardonForm();
		PresidentialPardonForm(string target);
		PresidentialPardonForm(const PresidentialPardonForm &a);
		PresidentialPardonForm & operator= (const PresidentialPardonForm &a);
		~PresidentialPardonForm();
		//others
		string	getTarget() const;
		void	smtg() const;
		static AForm *fncPtr(string target);
	private:
		string target;
};

#endif