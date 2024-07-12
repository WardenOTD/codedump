#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <iterator>
# include <cstring>

using std::cout;
using std::endl;

class Invalid : public std::exception {
	public:
		const char *what() const throw(){
			return ("Invalid Char");
		}
};

class Full : public std::exception {
	public:
		const char *what() const throw(){
			return ("Array Is Full");
		}
};

class NoSpan : public std::exception {
	public:
		const char *what() const throw(){
			return ("Array Contains 1 Number Or Less");
		}
};

class Span{
	public:
		Span(unsigned int N);
		Span(const Span &a);
		Span &operator=(const Span &a);
		~Span();

		void				addNumber(int i);
		void				addMoreNumber(std::vector<int> input);
		int					shortestSpan();
		int					longestSpan();

		unsigned int		getN() const;
		void				setN(unsigned int N);
		std::vector<int>	getContain() const;
		void				setContain(std::vector<int> contain);
	private:
		unsigned int N;
		std::vector<int> contain;
};

#endif
