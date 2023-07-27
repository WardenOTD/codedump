#include "FragTrap.hpp"

int	main()
{
	std::string	target1 = "Arnold";
	std::string	target2 = "Ronald";
	std::string	target3 = "Donald";
	ClapTrap	A(target1);
	ClapTrap	B(A);
	ClapTrap	C;

	ScavTrap	D(target2);
	ScavTrap	E(D);
	ScavTrap	F;

	FragTrap	G(target3);
	FragTrap	H(G);
	FragTrap	I;

	C = B;
	F = E;
	I = H;

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
	G.highFivesGuys();
	G.attack(target1);
	C.takeDamage(30);
	G.takeDamage(9000);
	G.highFivesGuys();
}
