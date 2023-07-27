#include "FragTrap.hpp"

// Orthodox Canonical Class Form
FragTrap::FragTrap(){
	std::cout << "FRAGTRAP ONLINE, WHAT YOU WAKE ME UP FOR ?" << std::endl;
}

FragTrap::FragTrap(const FragTrap &st){
	std::cout << "WHAT THE HELL YOU CLONED ME !!??" << std::endl;
	*this = st;
}

FragTrap &FragTrap::operator= (const FragTrap &st){
	std::cout << "YOU EVEN CLONING MY MEMORIES !!??" << std::endl;
	if (this != &st){
		name = st.name;
		HP = st.HP;
		EP = st.EP;
		AD = st.AD;
	}
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "\nIM GONNA EXPLO__---adsaokjhd---aaaaAAAaAa...\nBot ID: " << name << "\nRemaining HP: " << HP << std::endl;
	std::cout << "Remaining EP: " << EP << "\nBot Damage Modifier: " << AD << std::endl;
	std::cout << "\nBot Remains Have Been Incinerated" << std::endl;
}



// Others
FragTrap::FragTrap(std::string name){
	std::cout << "FRAGTRAP: " << name << " ONLINE WHAT YOU WAKE ME UP FOR ?" << std::endl;
	this->name = name;
	this->HP = 100;
	this->EP = 100;
	this->AD = 30;
}

void	FragTrap::highFivesGuys(){
	if (HP > 0)
		std::cout << "SOMEONE GIVE ME A HIGHFIVE RIGHT NOW OR ELSE IM GONNA EXPLODE!" << std::endl;
	else
		std::cout << "SuRelY i AAAm Allll RiGGG Httttt eEEEEEEEEEEEEE" << std::endl;
}
