#include "easyfind.hpp"
#include <vector>

int main(){
	std::vector<int> contain;

	for (int i = 0; i < 10; i++)
		contain.push_back(i);

	for (int i = 0; i < 15; i++){
		try{
			std::vector<int>::iterator T = easyfind(contain, i);
			cout << i << " found" << endl;
		}
		catch (std::exception &e){
			cout << i << " " << e.what() << endl;
		}
	}
}
