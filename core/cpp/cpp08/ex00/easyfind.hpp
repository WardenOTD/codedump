#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>

using std::cout;
using std::endl;

class NotFound : public std::exception {
	public:
		const char *what() const throw(){
			return ("Not Found");
		}
};

template <typename T> typename T::iterator easyfind(T coi, int b){
	typename T::iterator found;
	found = find(coi.begin(), coi.end(), b);
	if (found == coi.end())
		throw NotFound();
	return (found);
}

#endif
