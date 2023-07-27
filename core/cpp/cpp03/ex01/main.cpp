#include "ScavTrap.hpp"

int	main()
{
	std::string	target1 = "Arnold";
	std::string	target2 = "Ronald";
	ClapTrap	A(target1);
	ClapTrap	B(A);
	ClapTrap	C;

	ScavTrap	D(target2);
	ScavTrap	E(D);
	ScavTrap	F;

	C = B;
	F = E;

	A.attack(target2);
	D.takeDamage(0);
	A.beRepaired(100);
	D.beRepaired(0);
	D.attack(target1);
	A.takeDamage(20);
	D.guardGate();
	D.attack(target1);
	A.takeDamage(9999999);
	B.attack(target2);
	D.takeDamage(9999999);
	D.guardGate();
}
