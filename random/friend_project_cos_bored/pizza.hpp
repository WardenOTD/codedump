#ifndef PIZZA_HPP
# define PIZZA_HPP

# include <iostream>
# include <string>
# include <iomanip>

using namespace std;

class Receipt {
	public:
		// Orthodox Canonical Class Form
		Receipt();
		Receipt(const Receipt &a);
		Receipt & operator= (const Receipt &a);
		~Receipt();
		// Others
		void	getNamePhn();
		void	getSize();
		void	getOthers();
		void	calcPrice();
		void	pr();
		string	trunc(int len, char repl);
	private:
		string		name;
		string		phn;
		char		size;
		int			type;
		int			topping[3];
		float		size_price;
		float		type_price;
		float		topping_price;
		float		total_price;
};

int	isNumber(string str);

#endif
