#include "RPN.hpp"

RPN::RPN(){
	cout << "constructor" << endl;
}

RPN::RPN(const RPN &a){
	cout << "copy constructor" << endl;
	this->poland = a.getPoland();
}

RPN &RPN::operator=(const RPN &a){
	cout << "equal operator overload" << endl;
	this->poland = a.getPoland();
	return (*this);
}

RPN::~RPN(){
	cout << "destructor" << endl;
}

void	RPN::setPoland(int num){
	poland.push(num);
}

stack<int>	RPN::getPoland() const{
	return (poland);
}

void	RPN::checkNum(string inp){
	int	flag = 0;
	for (int i = 0; i <= (int)inp.size(); i++){
		if (flag > 1 || flag < 0)
			throw (WrongFormat());
		if (inp[i] != ' ')
			++flag;
		if (inp[i] == ' ')
			--flag;
	}
}

void	RPN::checkOperator(string inp){
	for (int i = 0; i < (int)inp.size(); i++){
		switch(inp[i]){
			case '0' ... '9':
				break ;
			case '+': case '-': case '/': case '*': case ' ':
				break ;
			default:
				throw (WrongOperator());
		}
	}
}

void	RPN::runRPN(string inp){
	try{
		checkNum(inp);
		checkOperator(inp);
		for (int i = 0, flag = 0; i < (int)inp.size(); i++){
			switch(inp[i]){
				case '0' ... '9':
					setPoland(inp[i] - '0');
					flag++;
					break ;
				case '+': case '-': case '/': case '*':
					if (flag == 1)
						throw (WrongPoland());
					doOperation(inp[i]);
					flag--;
					break ;
				case ' ':
					break ;
			}
		}
		if (poland.size() != 1){
			stack<int> tmp;
			while (!poland.empty()){
				tmp.push(poland.top());
				poland.pop();
			}
			cout << "multiple numbers remaining: ";
			while (!tmp.empty()){
				cout << tmp.top() << " ";
				tmp.pop();
			}
			cout << endl;
		}
		else
			cout << poland.top() << endl;
	}
	catch(std::exception &e){
		cout << e.what() << endl;
	}
}

void	RPN::doOperation(char op){
	int	t1 = 0, t2 = 0;
	switch(op){
		case '+':
			t1 = poland.top();
			poland.pop();
			t2 = poland.top();
			poland.pop();
			poland.push(t2 + t1);
			break ;
		case '-':
			t1 = poland.top();
			poland.pop();
			t2 = poland.top();
			poland.pop();
			poland.push(t2 - t1);
			break ;
		case '/':
			t1 = poland.top();
			poland.pop();
			t2 = poland.top();
			poland.pop();
			poland.push(t2 / t1);
			break ;
		case '*':
			t1 = poland.top();
			poland.pop();
			t2 = poland.top();
			poland.pop();
			poland.push(t2 * t1);
			break ;
	}
}

std::ostream & operator<<(std::ostream &out, const RPN &a){
	stack<int> tmp = a.getPoland();
	while (!tmp.empty()){
		out << tmp.top() << " ";
		tmp.pop();
	}
	return (out << endl);
}