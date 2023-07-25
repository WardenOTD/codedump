#include "phb.hpp"

void	Contact::set_info(int id, std::string info)
{
	if (id == 1)
		firstname.assign(info);
	if (id == 2)
		lastname.assign(info);
	if (id == 3)
		nickname.assign(info);
	if (id == 4)
		phonenum.assign(info);
	if (id == 5)
		darkestsecret.assign(info);
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
	if (current < 8)
		current++;
	if (!exist)
		exist = 1;
}

void	Contact::display_info()
{
	std::cout << "First Name: " << firstname << std::endl;
	std::cout << "Last Name: " << lastname << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phonenum << std::endl;
	std::cout << "Darkest Secret: " << darkestsecret << std::endl << std::endl;
}

std::string	Contact::trunc(std::string str, int len, char repl)
{
	std::string	tmp;
	if (!str.compare("firstname"))
	{
		if (len >= (int)firstname.length())
			return (tmp.assign(firstname));
		tmp = firstname.substr(0, (len - 1));
		tmp.push_back(repl);
		return (tmp);
	}
	if (!str.compare("lastname"))
	{
		if (len >= (int)lastname.length())
			return (tmp.assign(lastname));
		tmp = lastname.substr(0, (len - 1));
		tmp.push_back(repl);
		return (tmp);
	}
	if (!str.compare("nickname"))
	{
		if (len >= (int)nickname.length())
			return (tmp.assign(nickname));
		tmp = nickname.substr(0, (len - 1));
		tmp.push_back(repl);
		return (tmp);
	}
	return (NULL);
}

void	PhoneBook::searchcontact()
{
	unsigned int	i;
	std::string		index;
	unsigned int	id;

	if (!exist)
	{
		std::cout << "Empty PhoneBook!" << std::endl;
		return ;
	}
	i = 0;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	while (i < 8)
	{
		if (i == current)
			break ;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << (i+1) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << cntc[i].trunc("firstname", 10, '.') << "|";
		std::cout << std::setfill(' ') << std::setw(10) << cntc[i].trunc("lastname", 10, '.') << "|";
		std::cout << std::setfill(' ') << std::setw(10) << cntc[i].trunc("nickname", 10, '.') << "|" << std::endl;
		i++;
	}
	while (1)
	{
		std::cout << "Index Of Requested Information: ";
		getline(std::cin, index);
		if (!isNumber(index))
		{
			std::cout << "Invalid Index" << std::endl;
			continue ;
		}
		id = std::stoi(index);
		id -= 1;
		if (id < 0 || id >= i)
		{
			std::cout << "Invalid Index" << std::endl;
			continue ;
		}
		cntc[id].display_info();
		break ;
	}
}

void	PhoneBook::init()
{
	last = 0;
	current = 0;
	exist = 0;
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
		if (!AAAAAA.compare("SEARCH"))
			cringe.searchcontact();
		else if (!AAAAAA.compare("EXIT"))
			break ;
		else
			std::cout << "Invalid Input" << std::endl;
	}
}
