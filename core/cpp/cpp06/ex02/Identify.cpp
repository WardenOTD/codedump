#include "Identify.hpp"

Base *generate(void){
	Base * ret;
	srand(time(NULL) + rand());
	if (rand() % 2){
		srand(time(NULL) + rand());
		if (rand() % 2){
			ret = new C;
			return (ret);
		}
		ret = new B;
		return (ret);
	}
	else{
		ret = new A;
		return (ret);
	}
}

void identify(Base *p){
	if (dynamic_cast<A*>(p) != NULL)
		cout << "Is A" << endl;
	else if (dynamic_cast<B*>(p) != NULL)
		cout << "Is B" << endl;
	else if (dynamic_cast<C*>(p) != NULL)
		cout << "Is C" << endl;
}

void identify(Base &p){
	try{
		dynamic_cast<A&>(p);
		cout << "Is A" << endl;
	}
	catch(std::exception &e){
		try{
			dynamic_cast<B&>(p);
			cout << "Is B" << endl;
		}
		catch(std::exception &e){
			try{
				dynamic_cast<C&>(p);
				cout << "Is C" << endl;
			}
			catch(std::exception &e){
				return ;
			}
		}
	}
}

