#include "ScalarConverter.hpp"

void printall(char ccon, int icon, float fcon, double dcon, string in){
	if (dcon <= std::numeric_limits<char>::max() && dcon >= std::numeric_limits<char>::min()){
		if (isprint(ccon))
			cout << "Char : '" << ccon << "'" << endl;
		else
			cout << "Char : Non Displayable" << endl;
	}
	else
		cout << "Char : Impossible" << endl;
	if (dcon <= std::numeric_limits<int>::max() && dcon >= std::numeric_limits<int>::min())
		cout << "Int : " << icon << endl;
	else
		cout << "Int : Impossible" << endl;
	if ((in.find('.') != std::string::npos)){
		cout << "Float : " << std::fixed << fcon << "f" << endl;
		cout << "Double : " << std::fixed << dcon << endl;
	}
	else{
		cout << "Float : " << std::fixed << std::setprecision(1) << fcon << "f" << endl;
		cout << "Double : " << std::fixed << std::setprecision(1) << dcon << endl;
	}
}

void c_char(string in){
	char ccon = in[0];
	int icon = static_cast<int> (ccon);
	float fcon = static_cast<float> (ccon);
	double dcon = static_cast<double> (ccon);
	printall(ccon, icon, fcon, dcon, in);
}

void c_int(string in){
	int icon = atoi(in.c_str());
	char ccon = static_cast<char> (icon);
	float fcon = static_cast<float> (icon);
	double dcon = static_cast<double> (icon);
	printall(ccon, icon, fcon, dcon, in);
}

void c_float(string in){
	float fcon = strtof(in.c_str(), 0);
	int icon = static_cast<int> (fcon);
	char ccon = static_cast<char> (fcon);
	double dcon = static_cast<double> (fcon);
	printall(ccon, icon, fcon, dcon, in);
}

void c_double(string in){
	double dcon = strtod(in.c_str(), 0);
	int icon = static_cast<int> (dcon);
	char ccon = static_cast<char> (dcon);
	float fcon = static_cast<float> (dcon);
	printall(ccon, icon, fcon, dcon, in);
}

int ford(string in){
	if (in[in.length()-1] == 'f')
		return (3);

	// double dub = strtod(in.c_str(), 0);
	// if (dub > std::numeric_limits<int>::max() || dub < std::numeric_limits<int>::min())
	// 	return (4);
	return (4);
}

bool ifd(string in){
	bool precision = false;
	int end = in.length();
	int begin = (in[0] == '+' || in[0] == '-');
	if (in[end - 1] == 'f')
		end -= 1;
	for (int i = begin; i < end; ++i){
		if (!isdigit(in[i])){
			if (in[i] == '.'){
				if (precision == true)
					return (false);
				precision = true;
			}
			else
				return (false);
		}
	}
	return (true);
}

int parse(string in){
	/*
		# 0 = ERROR
		# 1 = CHAR
		# 2 = INT
		# 3 = FLOAT
		# 4 = DOUBLE
	*/
	// valid str
	if (!in.length())
		return (0);
	// pseudo literals for float / double
	if(!(in.compare("+inff")) || !(in.compare("-inff")) || !(in.compare("nanf")))
		return (3);
	if(!(in.compare("+inf")) || !(in.compare("-inf")) || !(in.compare("nan")))
		return (4);

	// check char
	if (in.length() == 1 && !isdigit(in[0]))
		return (1);
	// Only numeric inputs left to test
	// Make sure string is either INT, FLOAT or DOUBLE
	if (!ifd(in))
		return (0);
	// If has precision, check for float (f), else return double
	if (in.find('.') != std::string::npos)
		return (ford(in));
	// Only INT left
	return (2);
}

void ScalarConverter::convert(string in){
	switch(parse(in)){
		case 1: // CHAR
			c_char(in);
			break ;
		case 2: // INT
			c_int(in);
			break ;
		case 3: // FLOAT
			c_float(in);
			break ;
		case 4: // DOUBLE
			c_double(in);
			break ;
		default:
			cout << "Input Value Error" << endl;
			break ;
	}
}


ScalarConverter::ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter &a){
	*this = a;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &a){
	*this = a;
	return (*this);
}

ScalarConverter::~ScalarConverter(){

}

