#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>
# include <iterator>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:

		MutantStack(){
		}
		MutantStack(MutantStack<T, Container> &a){
			*this = a;
		}
		MutantStack<T, Container> &operator=(MutantStack<T, Container> &a){
			this->c = a.c;
		}
		~MutantStack(){
		}

		typedef typename Container::iterator iterator;
		iterator begin(){
			return (this->c.begin());
		}
		iterator end(){
			return (this->c.end());
		}
};

#endif
