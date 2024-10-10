#include "Identify.hpp"

int main(){
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;
}
