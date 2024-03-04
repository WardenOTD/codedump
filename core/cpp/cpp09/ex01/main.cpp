#include "RPN.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		cout << "please provide reverse Polish notation" << endl;
		exit (1);
	}
	string inp(argv[1]);
	RPN polish;
	polish.runRPN(inp);
}