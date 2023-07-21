#ifndef PHB_HPP
# define PHB_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
	public:
		void	set_info(int id, std::string info);
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
		int		last;

};

#endif
