#include "BitcoinExchange.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		cout << "please provide input.txt" << endl;
		exit (1);
	}
	(void) argv;
	BitcoinExchange	btc;
	btc.grabCsv();
	cout << btc << endl;
}