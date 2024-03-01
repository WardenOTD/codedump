#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::map;

class NotPositive : std::exception {
	public:
		const char *what() const throw(){
			return ("Error: non positive number");
		}
};

class BadInput : std::exception {
	public:
		const char *what() const throw(){
			return ("Error: bad input");
		}
};

class TooLarge : std::exception {
	public:
		const char *what() const throw(){
			return ("Error: number too large");
		}
};

class BitcoinExchange{
	public:
		//occf
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &a);
		BitcoinExchange &operator=(const BitcoinExchange &a);
		~BitcoinExchange();

		//others
		void	grabCsv();
		void	setData(string date, int rate);
		map<string, float>	getData() const;
		void	readInput(char *input);
		bool	cutInput(string line);
		bool	checkDate();
		void	action();
	private:
		map<string, float> data;
		string	inYear;
		float	inRate;
		NotPositive NotPositiveExe;
		BadInput BadInputExe;
		TooLarge TooLargeExe;
};

bool	isDigit(int i);
std::ostream & operator<< (std::ostream &out, const BitcoinExchange &btc);

#endif