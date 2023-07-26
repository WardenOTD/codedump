#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl{
	public:
		void	complain(std::string level);
		Harl();
		~Harl();
	private:
		// void	(*functptr[4])();
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};


#endif
