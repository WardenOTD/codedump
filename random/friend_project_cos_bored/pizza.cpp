#include "pizza.hpp"

Receipt::Receipt(){
}

Receipt::Receipt(const Receipt &a){
	*this = a;
}

Receipt & Receipt::operator= (const Receipt &a){
	if (this != &a){
		name.assign(a.name);
		phn.assign(a.phn);
		type = a.type;
		topping = a.topping;
		type_price = a.type_price;
		topping_price = a.topping_price;
	}
	return (*this);
}

Receipt::~Receipt(){
}

void Receipt::getNamePhn(){
	while (1){
		cout << "Name: ";
		getline(cin, name);
		if (cin.eof())
			exit(1);
		if (cin.length())
			break ;
		cout << "Empty Field" << endl;
	}
	while (1){
		cout << "Phone Number: ";
		getline(cin, phn);
		if (cin.eof())
			exit(1);
		if (!phn.length())
		{
			cout << "Empty Field!" << endl;
			continue ;
		}
		if (isNumber(phn) && phn.length() == 10)
			break ;
		cout << "Not Valid Number" << endl;
	}
}

int	isNumber(string str)
{
	int	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	Receipt::getSize(){
	string	input;
	while (1){
		cout << "Select Size, S-small, M-medium, L-large" << endl << "> ";
		getline(cin, input);
		if (cin.eof())
			exit(1);
		if (!input.compare("S") || !input.compare("s"))
			break ;
		if (!input.compare("M") || !input.compare("m"))
			break ;
		if (!input.compare("L") || !input.compare("l"))
			break ;
		cout << "Invalid Size" << endl;
	}
	size = toupper(*input);
}

void	Receipt::getOthers(){
	string input;
	int		i = 0;
	while (1){
		cout << "Choose 1: Margherita, Pepperoni, Hawaiian" << endl << "> ";
		getline(cin, input);
		if (cin.eof())
			exit(1);
		if (!input.compare("Margherita") || !input.compare("margherita")){
			type = 1;
			break ;
		}
		if (!input.compare("Pepperoni") || !input.compare("pepperoni")){
			type = 2;
			break ;
		}
		if (!input.compare("Hawaiian") || !input.compare("hawaiian")){
			type = 3;
			break ;
		}
		cout << "Invalid Choice" << endl;
	}
	while (1){
		cout << "Choose up to 3: Mushrooms, Onions, Peppers, Extra Cheese" << endl << i+1 << "> ";
		getline(cin, input);
		if (cin.eof())
			exit(1);
		if (!input.compare("Mushrooms") || !input.compare("mushrooms")){
			topping[i] = 1;
			i++;
			break ;
		}
		if (!input.compare("Onions") || !input.compare("onions")){
			topping[i] = 2;
			i++;
			break ;
		}
		if (!input.compare("Peppers") || !input.compare("peppers")){
			topping[i] = 3;
			i++;
			break ;
		}
		if (!input.compare("Extra Cheese") || !input.compare("extra cheese") \
			|| !input.compare("Extra cheese") || !input.compare("extra Cheese")){
			topping[i] = 4;
			i++;
			break ;
		}
		cout << "Invalid Choice" << endl;
	}
}

void	Receipt::calcPrice(){
	if (size == 'S')
		size_price = 15;
	else if (size == 'M')
		size_price = 19;
	else if (size == 'L')
		size_price = 23;
	type_price = 7 + ((type - 1) * 7);
	topping_price = 0;
	for (int i = 0; i < 3; i++){
		if (topping[i] == 1)
			topping_price += 2.8;
		else if (topping[i] == 2)
			topping_price += 1.2;
		else if (topping[i] == 3)
			topping_price += 3.3;
		else if (topping[i] == 4)
			topping_price += 3.5;
	}
	total_price = size_price + type_price + topping_price;
}

void	Receipt::pr(){
	cout << "|" << setfill(' ') << setw(12) << Receipt::trunc(12, '.') << "|" << endl;
	cout << "|" << setfill(' ') << setw(12) << phn << "|" << endl;
	cout << "|" << setfill(' ') << setw(12) << size << "|" << endl;
	cout << "|" << setfill(' ') << setw(12) << "------------" << "|" << endl;
	if (type == 1)
		cout << "|" << setfill(' ') << setw(12) << "Margherita" << "|" << endl;
	else if (type == 2)
		cout << "|" << setfill(' ') << setw(12) << "Pepperoni" << "|" << endl;
	else if (type == 3)
		cout << "|" << setfill(' ') << setw(12) << "Hawaiian" << "|" << endl;
	cout << "|" << setfill(' ') << setw(12) << "------------" << "|" << endl;
	for (int i = 0; i < 3; i++){
		if (topping[i] == 1)
			cout << "|" << setfill(' ') << setw(12) << "Mushrooms" << "|" << endl;
		else if (topping[i] == 2)
			cout << "|" << setfill(' ') << setw(12) << "Onions" << "|" << endl;
		else if (topping[i] == 3)
			cout << "|" << setfill(' ') << setw(12) << "Peppers" << "|" << endl;
		else if (topping[i] == 4)
			cout << "|" << setfill(' ') << setw(12) << "Extra Cheese" << "|" << endl;
	}
	cout << "|" << setfill(' ') << setw(12) << "------------" << "|" << endl;
	cout << "|" << setfill(' ') << setw(12) << "------------" << "|" << endl;
	cout << "|" << setfill(' ') << setw(7) << "$" << fixed << setprecision(2) << total_price  << "|" << endl;
}

string	Receipt::trunc(int len, char repl)
{
	string	tmp;
	if (len >= (int)name.length())
		return (tmp.assign(name));
	tmp = name.substr(0, (len - 1));
	tmp.push_back(repl);
	return (tmp);
}
