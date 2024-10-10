#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		cout << "1 number please" << endl;
		return (1);
	}
	string in(argv[1]);
	ScalarConverter::convert(in);
}
