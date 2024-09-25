#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

using std::cout;
using std::endl;

template <typename T> void swap(T &va, T &vb){
	T temp = va;
	va = vb;
	vb = temp;
}

template <typename T> T min(T va, T vb){
	if (va < vb)
		return va;
	return vb;
}

template <typename T> T max(T va, T vb){
	if (va > vb)
		return va;
	return vb;
}

#endif
