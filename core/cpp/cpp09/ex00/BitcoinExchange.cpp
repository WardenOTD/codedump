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
	int				irate;

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

void	BitcoinExchange::setData(string date, int rate){
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
		if (!cutInput(line)){
			throw (BitcoinExchange::BadInputExe);
			continue ;
		}
		else if (!checkDate()){
			throw (BitcoinExchange::BadInputExe);
			continue ;
		}
		else if (inRate < 0){
			throw (BitcoinExchange::NotPositiveExe);
			continue ;
		}
		else if (inRate > 1000){
			throw (BitcoinExchange::TooLargeExe);
			continue ;
		}
		//action;
	}
	file.close();
}

bool	BitcoinExchange::cutInput(string line){
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
		return (false);
	try{
		tmp = line.substr(13, string::npos);
	}
	catch (const std::out_of_range &oor){
		return (false);
	}
	inRate = std::stof(tmp);
	return (true);
}

bool	BitcoinExchange::checkDate(){
	try{
		string	year = inYear.substr(0, 4);
		string	month = inYear.substr(5, 2);
		string day = inYear.substr(8, 2);
		int	mon = std::stoi(month);
		int	da = std::stoi(day);
		if (mon > 12 || mon < 1)
			return (false);
		switch(mon){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if (da > 31 || da < 1)
					return (false);
				break ;
			case 2:
				if (da > 29 || da < 1)
					return (false);
				break ;
			case 4: case 6: case 9: case 11:
				if (da > 30 || da < 1)
					return (false);
				break ;
		}
	}
	catch (const std::out_of_range &oor){
		return (false);
	}
	return (true);
}

void	BitcoinExchange::action(){
	map<string, float>::iterator itr = data.find(inYear);
	string	year = inYear.substr(0, 4);
	string	month = inYear.substr(5, 2);
	string day = inYear.substr(8, 2);
	
	while (itr != data.end()){
		
	}
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