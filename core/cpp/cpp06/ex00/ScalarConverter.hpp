#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class ScalarConverter {
	public:
		void convert(string in);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &a);
		ScalarConverter & operator=(const ScalarConverter &a);
		~ScalarConverter();
};

#endif
