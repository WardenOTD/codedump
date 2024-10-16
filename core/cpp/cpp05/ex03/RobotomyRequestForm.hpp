#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include <cstdlib>

using std::string;
using std::cout;
using std::endl;

class RobotomyRequestForm : public AForm{
	public:
		//OCCF
		RobotomyRequestForm();
		RobotomyRequestForm(string target);
		RobotomyRequestForm(const RobotomyRequestForm &a);
		RobotomyRequestForm & operator= (const RobotomyRequestForm &a);
		~RobotomyRequestForm();
		//others
		string	getTarget() const;
		void	smtg() const;
		static AForm *fncPtr(string target);
	private:
		string target;
};

#endif
