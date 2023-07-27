#include "ClapTrap.hpp"


/* Orthodox Canonical Class Form */
ClapTrap::ClapTrap(){
	std::cout << "ClapTrap online, what you wake me up for ?" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct){
	std::cout << "What the hell, you cloned me !!??" << std::endl;
	*this = ct;
}

ClapTrap &ClapTrap::operator= (const ClapTrap &ct){
	std::cout << "You even cloning my memories !!??" << std::endl;
	if (this != &ct){
		name = ct.name;
		HP = ct.HP;
		EP = ct.EP;
		AD = ct.AD;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "\nSuch pain...\nBot ID: " << name << "\nRemaining HP: " << HP << std::endl;
	std::cout << "Remaining EP: " << EP << "\nBot Damage Modifier: " << AD << std::endl;
	std::cout << "\nBot Remains Have Been Incinerated" << std::endl;
}



/* Others */
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap: " << name << " online, what you wake me up for ?" << std::endl;
	this->name = name;
	this->HP = 10;
	this->EP = 10;
	this->AD = 0;
}

void	ClapTrap::attack(const std::string &target)
{
	if (EP > 0 && HP > 0)
	{
		std::cout << "[" << name << "] attacks [" << target << "] for " << AD << " hit points." << std::endl;
		--EP;
	}
	else if (HP > 0)
		std::cout << "Out of energy!" << std::endl;
	else
		std::cout << "Can't attack, already dead!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (HP > 0)
	{
		std::cout << "[" << name << "] took " << amount << " damage!";
		HP -= amount;
		if (HP < 0)
			std::cout << " Overkill!";
		std::cout << std::endl << "[" << name << "] now has " << HP << " HP!" << std::endl;
	}
	else
		std::cout << "Can't get hurt if it's already dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (EP > 0 && HP > 0)
	{
		std::cout << "[" << name << "] has repaired itself for " << amount << " HP!";
		HP += amount;
		std::cout << std::endl << "[" << name << "] now has " << HP << " HP!" << std::endl;
		--EP;
	}
	else if (HP > 0)
		std::cout << "Out of energy!" << std::endl;
	else
		std::cout << "Can't repair, already dead!" << std::endl;
}
