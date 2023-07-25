#ifndef PHB_HPP
# define PHB_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
	public:
		void		set_info(int id, std::string info);
		void		display_info();
		std::string	trunc(std::string str, int len, char repl);
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenum;
		std::string	darkestsecret;
};

class PhoneBook {
	public:
		void	init();
		void	addcontact();
		void	searchcontact();
	private:
		Contact	cntc[8];
		unsigned int	last;
		unsigned int	current;
		int				exist;

};

#endif
