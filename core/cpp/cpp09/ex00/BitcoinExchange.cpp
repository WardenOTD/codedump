#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	cout << "constructor" << endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &a){
	cout << "copy constructor" << endl;
	this->data = a.getData();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &a){
	cout << "equal operator overload" << endl;
	this->data = a.getData();
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){
	cout << "destructor" << endl;
}

void	BitcoinExchange::grabCsv(){
	std::fstream	csv;
	string			date;
	string			srate;
	float				irate;

	csv.open("data.csv", std::ios::in);
	getline(csv, date, '\n');
	// cout << "purge line:\t" << date << endl;
	while (getline(csv, date, ',')){
		getline(csv, srate, '\n');
		// cout << "date: " << date << "\trate: " << srate << endl;
		irate = std::stof(srate);
		this->setData(date, irate);
	}
	csv.close();
}

void	BitcoinExchange::setData(string date, float rate){
	data[date] = rate;
}

map<string, float>	BitcoinExchange::getData() const{
	return (data);
}

void	BitcoinExchange::readInput(char *input){
	std::fstream	file;
	string			line;

	file.open(input, std::ios::in);
	getline(file, line);
	while (getline(file, line)){
		try{
			cutInput(line);
			checkDate();
		}
		catch(std::exception &e){
			cout << e.what() << " => " << line << endl;
			continue ;
		}
		try{
			rateLimit();
		}
		catch(std::exception &e){
			cout << e.what() << endl;
			continue ;
		}
		try{
			action();
		}
		catch(std::exception &e){
			cout << e.what() << " => " << line << endl;
			continue ;
		}
	}
	file.close();
}

void	BitcoinExchange::cutInput(string line){
	string tmp;
	int	num = 0, dash = 0;

	inYear = line.substr(0, 10);
	for (int i = 0; i < (int)inYear.size(); ++i){
		if (isDigit(inYear[i]))
			num++;
		else if (inYear[i] == '-')
			dash++;
	}
	if (num != 8 || dash != 2)
		throw (BadInput());
	try{
		tmp = line.substr(13, string::npos);
	}
	catch (const std::out_of_range &oor){
		throw (BadInput());
	}
	inRate = std::stof(tmp);
}

void	BitcoinExchange::checkDate(){
	try{
		string	year = inYear.substr(0, 4);
		string	month = inYear.substr(5, 2);
		string day = inYear.substr(8, 2);
		int yea = std:: stoi(year);
		int	mon = std::stoi(month);
		int	da = std::stoi(day);
		if (yea < 1)
			throw (BadInput());
		if (mon > 12 || mon < 1)
			throw (BadInput());
		switch(mon){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if (da > 31 || da < 1)
					throw (BadInput());
				break ;
			case 2:
				if (da > 29 || da < 1)
					throw (BadInput());
				break ;
			case 4: case 6: case 9: case 11:
				if (da > 30 || da < 1)
					throw (BadInput());
				break ;
		}
	}
	catch (const std::out_of_range &oor){
		throw (BadInput());
	}
}

void	BitcoinExchange::rateLimit(){
	if (inRate < 0)
		throw (NotPositive());
	else if (inRate > 1000)
		throw (TooLarge());
}

void	BitcoinExchange::action(){
	map<string, float>::iterator itr = data.lower_bound(inYear);
	// string year, month, day;
	// try{
	// 	year = inYear.substr(0, 4);
	// 	month = inYear.substr(5, 2);
	// 	day = inYear.substr(8, 2);
	// }
	// catch(const std::out_of_range &oor){
	// 	throw (BadInput());
	// }
	// int	yea = std::stoi(year);
	// int mont = std::stoi(month);
	// int da = std::stoi(day);
	
	// while (itr != data.end()){
	// 	if (da == 1){
	// 		if (mont == 1){
	// 			if (yea == 1){
	// 				throw (BadInput());
	// 				break ;
	// 			}
	// 			yea--;
	// 			mont = 12;
	// 			da = 31;
	// 		}
	// 		else{
	// 			mont--;
	// 			switch(mont){
	// 			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	// 				da = 31;
	// 				break ;
	// 			case 2:
	// 				da = 29;
	// 				break ;
	// 			case 4: case 6: case 9: case 11:
	// 				da = 30;
	// 				break ;
	// 			}
	// 		}
	// 	}
	// 	else
	// 		da--;
	// 	inYear.clear();
	// 	std::stringstream	sstr;
	// 	sstr << yea;
	// 	inYear.append(sstr.str());
	// 	inYear.append("-");
	// 	sstr.clear();
	// 	sstr << mont;
	// 	inYear.append(sstr.str());
	// 	inYear.append("-");
	// 	sstr.clear();
	// 	sstr << da;
	// 	inYear.append(sstr.str());
	// 	itr = data.find(inYear);
	// }
	if (inYear != itr->first){
		if (itr == data.begin()){
			throw (BadInput());
		}
		--itr;
	}
	cout << inYear << " => " << inRate << " = " << std::fixed << std::setprecision(2) << (inRate * itr->second) << endl;
}

bool	isDigit(int i){
	if (i >= '0' && i <= '9')
		return (true);
	return (false);
}

std::ostream & operator<< (std::ostream &out, const BitcoinExchange &btc){
	map<string, float>::iterator	itr;
	map<string, float> tmp = btc.getData();

	for (itr = tmp.begin(); itr != tmp.end(); ++itr){
		out << itr->first << "\t|\t" << itr->second << endl;
	}
	return (out);
}