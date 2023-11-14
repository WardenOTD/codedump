//Goofing around with my friend's project cause why not.



/*
	Requirement:
		Prompt user for Name and Phone Number;
		Size of S-small, M-medium, L-large;
		Type of Margherita, Pepperoni, Hawaiian;
		Up to 3 Mushrooms, Onions, Peppers, Extra Cheese;
		Generate receipt: Name, PN, Size, Type, Toppings, Cost;
		Handle Errors and Validate Input;
		Invalid Input, Appropriate Error Message To Be Printed;
*/

#include "pizza.hpp"

int	main()
{
	Receipt	pizza;
	pizza.getNamePhn();
	pizza.getSize();
	pizza.getOthers();
	pizza.calcPrice();
	pizza.pr();
}
