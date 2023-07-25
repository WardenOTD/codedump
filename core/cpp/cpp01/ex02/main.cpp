#include <iostream>
#include <string>

int	main()
{
	std::string	kys = "HI THIS IS BRAIN";
	std::string	*kysptr = &kys;
	std::string	&kysref = kys;
	std::cout << kysptr << std::endl << &kysref << std::endl;
	std::cout << *kysptr << std::endl << kysref << std::endl;
}
