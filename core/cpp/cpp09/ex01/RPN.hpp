#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

class	WrongFormat : public std::exception{
	public:
		const char *what() const throw(){
			return("Error: wrong format- \
1 space between numbers and operations, no double digit numbers");
		}
};

class	WrongOperator : public std::exception{
	public:
		const char *what() const throw(){
			return ("Error: invalid token");
		}
};

class	WrongPoland : public std::exception{
	public:
		const char *what() const throw(){
			return ("Error: invalid RPN string- valid ex: [2 3 + 4 * 2 / 3 7 - -]");
		}
};

class RPN{
	public:
		//occf
		RPN();
		RPN(const RPN &a);
		RPN &operator=(const RPN &a);
		~RPN();

		//others
		void	setPoland(int num);
		stack<int> getPoland() const;
		void	checkNum(string inp);
		void	checkOperator(string inp);
		void	runRPN(string inp);
		void	doOperation(char op);
	private:
		stack<int> poland;
};

std::ostream & operator<<(std::ostream &out, const RPN &a);

#endif