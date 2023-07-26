#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	void	(Harl::*functptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	if (!level.compare("DEBUG"))
		(this->*functptr[0])();
	else if (!level.compare("INFO"))
		(this->*functptr[1])();
	else if (!level.compare("WARNING"))
		(this->*functptr[2])();
	else if (!level.compare("ERROR"))
		(this->*functptr[3])();
}

Harl::Harl()
{
	std::cout << "Harl" << std::endl;
	// void	(Harl::*functptr[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	// (*functptr)[0] = &Harl::debug;
	// (*functptr)[1] = &Harl::info;
	// (*functptr)[2] = &Harl::warning;
	// (*functptr)[3] = &Harl::error;
}

Harl::~Harl()
{
	std::cout << "Harl Tripped And Snapped His Neck" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put\nenough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for\nyears whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
