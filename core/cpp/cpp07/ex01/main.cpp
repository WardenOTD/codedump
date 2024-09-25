#include "iter.hpp"
#include "vector"
#include "string"
#include "iterator"

using std::string;
using std::vector;
using std::iterator;

void print_all(int arr1[], char arr2[], float arr3[], string str, vector<int> vec, int omit){
	cout << "arr1: ";
	for (int i = 0; i < 10; ++i){
		cout << arr1[i];
		if (i != 9)
			cout << ", ";
	}
	cout << endl;

	if (omit < 2){
		cout << "arr2: ";
		for (int i = 0; i < 10; ++i){
			cout << arr2[i];
			if (i != 9)
				cout << ", ";
		}
		cout << endl;
	}

	if (omit < 3){
		cout << "arr3: ";
		for (int i = 0; i < 10; ++i){
			cout << arr3[i];
			if (i != 9)
				cout << ", ";
		}
		cout << endl;
	}

	if (omit < 2)
		cout << "str: " << str << endl;

	cout << "vec: ";
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr){
		cout << *itr;
		if (itr != vec.end())
			cout << ", ";
	}
	cout << endl;
}

void reset(int arr1[], char arr2[], float arr3[], string str){
	for(int i = 0, arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; i < 10; ++i){
		arr1[i] = arr[i];
	}
	for(int i = 0; i < 10; ++i){
		char arr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		arr2[i] = arr[i];
	}
	for(int i = 0; i < 10; ++i){
		float arr[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.11};
		arr3[i] = arr[i];
	}
	str = "Hello World!";
}

int main(){
	int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char arr2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	float arr3[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.11};
	string str = "Hello World!";
	vector<int> vec1, vec2, vec3, vec4, vec5;
	for(int i = 0, arr[10] = {123, 456, 789, 223, 556, 889, 323, 656, 989, 1234}; i < 10; ++i){
		vec1.push_back(arr[i]);
		vec2.push_back(arr[i]);
		vec3.push_back(arr[i]);
		vec4.push_back(arr[i]);
		vec5.push_back(arr[i]);
	}

	cout << endl << "original" << endl;
	print_all(arr1, arr2, arr3, str, vec1, 1);

	cout << endl << "add 5" << endl;
	iter(arr1, 10, &add);
	iter(arr2, 10, &add);
	iter(arr3, 10, &add);
	iter(str, 10, &add);
	iter(vec1, 10, &add);

	print_all(arr1, arr2, arr3, str, vec1, 1);
	reset(arr1, arr2, arr3, str);

	cout << endl << "sub 5" << endl;
	iter(arr1, 10, &sub);
	iter(arr2, 10, &sub);
	iter(arr3, 10, &sub);
	iter(str, 10, &sub);
	iter(vec2, 10, &sub);

	print_all(arr1, arr2, arr3, str, vec2, 1);
	reset(arr1, arr2, arr3, str);

	cout << endl << "mul 5" << endl;
	iter(arr1, 10, &mul);
	// iter(arr2, 10, &mul);
	iter(arr3, 10, &mul);
	// iter(str, 10, &mul);
	iter(vec3, 10, &mul);

	print_all(arr1, arr2, arr3, str, vec3, 2);
	reset(arr1, arr2, arr3, str);

	cout << endl << "div 5" << endl;
	iter(arr1, 10, &div);
	// iter(arr2, 10, &div);
	iter(arr3, 10, &div);
	// iter(str, 10, &div);
	iter(vec4, 10, &div);

	print_all(arr1, arr2, arr3, str, vec4, 2);
	reset(arr1, arr2, arr3, str);

	cout << endl << "mod 5" << endl;
	iter(arr1, 10, &mod);
	// iter(arr2, 10, &mod);
	// iter(arr3, 10, &mod);
	// iter(str, 10, &mod);
	iter(vec5, 10, &mod);

	print_all(arr1, arr2, arr3, str, vec5, 3);

	return (0);
}
