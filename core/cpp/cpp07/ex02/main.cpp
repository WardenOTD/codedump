#include <iostream>
#include <cstdlib>
#include "Array.hpp"

using std::cout;
using std::endl;

/*
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/

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

	//size test
	cout << endl << "Size test" << endl;
	cout << "arr: " << arr.size() << endl;
	cout << "arr2: " << arr2.size() << endl;
	cout << "arr3: " << arr3.size() << endl;
	
	return (0);
}
