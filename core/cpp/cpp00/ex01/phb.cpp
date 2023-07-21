#include "phb.hpp"

void	Contact::set_info(int id, std::string info)
{
	if (id == 1)
		info.append(firstname);
	if (id == 2)
		info.append(lastname);
	if (id == 3)
		info.append(nickname);
	if (id == 4)
		info.append(phonenum);
	if (id == 5)
		info.append(darkestsecret);
}

std::string	get_info(std::string word)
{
	std::string	str;
	while (1)
	{
		std::cout << word;
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
		if (str.length())
			break ;
		std::cout << "Empty Field!" << std::endl;
	}
	return (str);
}

int	isNumber(std::string str)
{
	int	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

std::string	get_hpn()
{
	std::string	str;
	while (1)
	{
		std::cout << "Phone Number: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
		if (!str.length())
		{
			std::cout << "Empty Field!" << std::endl;
			continue ;
		}
		if (isNumber(str))
			break ;
		std::cout << "Not Valid Number" << std::endl;
	}
	return (str);
}

void	PhoneBook::addcontact()
{
	unsigned int	i;

	if (last > 7)
		std::cout << "Oldest Entry Will Be Overwritten" << std::endl;
	i = last % 8;
	cntc[i].set_info(1, get_info("First Name: "));
	cntc[i].set_info(2, get_info("Last Name: "));
	cntc[i].set_info(3, get_info("Nickname: "));
	cntc[i].set_info(4, get_hpn());
	cntc[i].set_info(5, get_info("Darkest Secret: "));
	last++;
}

void	PhoneBook::init()
{
	last = 0;
}

int	main()
{
	PhoneBook	cringe;
	std::string	AAAAAA;
	cringe.init();
	while (1)
	{
		std::cout << "ADD - New Contact\nSEARCH - Search Contacts\nEXIT - Exits Program" << std::endl;
		getline(std::cin, AAAAAA);
		if (std::cin.eof())
			exit(1);
		if (!AAAAAA.compare("ADD"))
			cringe.addcontact();
		else if (!AAAAAA.compare("EXIT"))
			break ;
		else
			std::cout << "bruv" << std::endl;
	}
}
