#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	public:
		//occf
		Array();
		Array(const Array<T> &a);
		Array<T> &operator=(const Array<T> &a);
		~Array();

		//subject
		Array(unsigned int N);
		T &operator[](const int index);
		T const &operator[](const int index) const;
		unsigned int size() const;

		class OutOfBounds : public std::exception {
			const char *what() const throw(){
				return ("Index Out Of Bounds");
			}
		};
	private:
		unsigned int	arr_size;
		T				*val;
};

# include "Array.tpp"

#endif
