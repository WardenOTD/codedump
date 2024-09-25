#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
// # include <vector>
// # include <typeinfo>

using std::cout;
using std::endl;
// using std::vector;

template <typename Container, typename T> void add(Container &va, T vb){
	va[vb] += 5;
}
template <typename Container, typename T> void sub(Container &va, T vb){
	// if (typeid(Container) == typeid(vector<int>)){
	// 	cout << endl << "vec" << endl;
	// 	cout << va[vb] << endl;
	// 	cout << va[vb] - 5 << endl;
	// 	va[vb] -= 5;
	// 	cout << va[vb] << endl;
	// 	return ;
	// }
	va[vb] -= 5;
}
template <typename Container, typename T> void mul(Container &va, T vb){
	va[vb] *= 5;
}
template <typename Container, typename T> void div(Container &va, T vb){
	va[vb] /= 5;
}
template <typename Container, typename T> void mod(Container &va, T vb){
	va[vb] %= 5;
}

template <typename Container, typename T> void iter(Container &arr, T len, void(*func)(Container &, T))
{
	for (T i = 0; i < len; ++i)
		func(arr, i);
}

#endif
