#include "MutantStack.hpp"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int difcon(){

	cout << endl << "Vector" << endl;

	vector<int>	mvect;

	mvect.push_back(5);
	mvect.push_back(17);

	cout << *mvect.begin() << endl;

	mvect.erase(mvect.begin());

	cout << *mvect.begin() << endl;

	cout << "line break" << endl;

	mvect.push_back(3);
	mvect.push_back(5);
	mvect.push_back(737);

	for (int i = 0, j = 1000; i != 20; i++, j++){
		mvect.push_back(j);
	}

	mvect.push_back(0);

	vector<int>::iterator it = mvect.begin();
	vector<int>::iterator ite = mvect.end();

	++it;
	--it;
	while (it != ite){
		cout << *it << endl;
		++it;
	}

	std::vector<int> s(mvect);
	return (0);
}

int main(){

	cout << "Stack" << endl;

	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	cout << mstack.top() << endl;

	mstack.pop();

	cout << mstack.top() << endl;

	cout << "line break" << endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	for (int i = 0, j = 1000; i != 20; i++, j++){
		mstack.push(j);
	}

	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite){
		cout << *it << endl;
		++it;
	}

	std::stack<int> s(mstack);
	difcon();
	return (0);
}
