#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : arr_size(0), val(NULL)
{}

template <typename T>
Array<T>::Array(const Array<T> &a) : val(NULL){
	*this = a;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &a){
	if (this->val)
		delete[] this->val;
	this->arr_size = a.arr_size;
	if (!a.arr_size)
		this->val = NULL;
	else{
		T *deep;
		deep = new T[arr_size]();
		for (int i = 0; i < (int)a.arr_size; ++i)
			deep[i] = a[i];
		this->val = deep;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(){
	if (val)
		delete[] val;
}

template <typename T>
Array<T>::Array(unsigned int N) : arr_size(N){
	val = new T[N]();
}

template <typename T>
T &Array<T>::operator[](const int index){
	if (index >= 0 && index < (int)arr_size)
		return (val[index]);
	throw (Array::OutOfBounds());
}

template <typename T>
T const &Array<T>::operator[](const int index) const{
	if (index >= 0 && index < (int)arr_size)
		return (val[index]);
	throw (Array::OutOfBounds());
}

template <typename T>
unsigned int Array<T>::size() const{
	return (arr_size);
}

#endif
