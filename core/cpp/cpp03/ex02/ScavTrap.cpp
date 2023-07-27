#include "ScavTrap.hpp"

/* Orthodox Canonical Class Form */
ScavTrap::ScavTrap(){
	std::cout << "ScavTrap online, what you wake me up for ?" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st){
	std::cout << "What the hell, you cloned me !!??" << std::endl;
	*this = st;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &st){
	std::cout << "You even cloning my memories !!??" << std::endl;
	if (this != &st){
		name = st.name;
		HP = st.HP;
		EP = st.EP;
		AD = st.AD;
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "\nHow cruel...\nBot ID: " << name << "\nRemaining HP: " << HP << std::endl;
	std::cout << "Remaining EP: " << EP << "\nBot Damage Modifier: " << AD << std::endl;
	std::cout << "\nBot Remains Have Been Incinerated" << std::endl;
}



/* Others */
ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap: " << name << " online, what you wake me up for ?" << std::endl;
	this->name = name;
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
}

void	ScavTrap::attack(const std::string &target)
{
	if (EP > 0 && HP > 0)
	{
		std::cout << "[" << name << "] slaps [" << target << "] for " << AD << " hit points." << std::endl;
		--EP;
	}
	else if (HP > 0)
		std::cout << "Out of energy!" << std::endl;
	else
		std::cout << "Can't attack, already dead!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (HP > 0)
	{
		std::cout << "ScavTrap [" << name << "] has entered GateKeep mode." << std::endl;
		std::cout << "You see this? It's mine! You can't have it! Only me!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap [" << name << "] tries his hardest to GateKeep..." << std::endl;
		std::cout << "But it failed! ScavTrap [" << name << "] is already dead!" << std::endl;
	}
}
