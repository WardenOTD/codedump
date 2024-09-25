#include <iostream>
#include <cstdlib>
#include "Array.hpp"

using std::cout;
using std::endl;

template <typename T>
void print_arr(Array<T> &arr){
	for (unsigned int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}

template <typename T>
void print_arr(const Array<T> &arr){
	for (unsigned int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	//empty arr, some exception tests
	cout << endl << "Empty array exception tests" << endl;
	Array<int> arr;
	try{
		cout << "assign at index [1] :: ";
		arr[1] = 10;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		cout << "assign at index [-1] :: ";
		arr[-1] = 10;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		cout << "assign at index [0] :: ";
		arr[0] = 10;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}


	//empty arr2 of size 15
	cout << endl << "Empty array of size 15" << endl;
	Array<int> arr2(15);
	cout << "arr2: ";
	print_arr(arr2);

	//fill arr2
	cout << endl << "Fill array" << endl;
	for (unsigned int i = 0; i < arr2.size(); ++i)
		arr2[i] = i + 10;
	cout << "arr2: ";
	print_arr(arr2);

	//copy assignment operator test
	cout << endl << "Copy assignment operator test" << endl;
	arr = arr2;
	cout << "arr: ";
	print_arr(arr);
	cout << "arr2: ";
	print_arr(arr2);

	//copy assignment operator deep copy test
	cout << endl << "Copy assignment operator deep copy test" << endl;
	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] *= 7;
	cout << "arr: ";
	print_arr(arr);
	cout << "arr2: ";
	print_arr(arr2);

	//copy constructor test
	cout << endl << "Copy constructor test" << endl;
	Array<int> arr3(arr2);
	cout << "arr3: ";
	print_arr(arr3);
	cout << "arr2: ";
	print_arr(arr2);

	//copy constructor deep copy test
	cout << endl << "Copy constructor deep copy test" << endl;
	for (unsigned int i = 0; i < arr3.size(); ++i)
		arr3[i] *= 10;
	cout << "arr3: ";
	print_arr(arr3);
	cout << "arr2: ";
	print_arr(arr2);

	//constant array test
	cout << endl << "Constant array test" << endl;
	const Array<int> constArr = arr2;
	cout << "constArr: ";
	print_arr(constArr);

	return (0);
}
