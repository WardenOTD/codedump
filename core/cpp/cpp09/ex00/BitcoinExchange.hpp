#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <iterator>
# include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::map;

class NotPositive : public std::exception {
	public:
		const char *what() const throw(){
			return ("Error: non positive number");
		}
};

class BadInput : public std::exception {
	public:
		const char *what() const throw(){
			return ("Error: bad input");
		}
};

class TooLarge : public std::exception {
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
		void	setData(string date, float rate);
		map<string, float>	getData() const;
		void	readInput(char *input);
		void	cutInput(string line);
		void	checkDate();
		void	rateLimit();
		void	action();
	private:
		map<string, float> data;
		string	inYear;
		float	inRate;
};

bool	isDigit(int i);
std::ostream & operator<< (std::ostream &out, const BitcoinExchange &btc);

#endif