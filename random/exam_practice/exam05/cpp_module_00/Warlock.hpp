#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Warlock {
	public:
		Warlock(string name, string title);
		~Warlock();
	
		string const &getName() const;
		string const &getTitle() const;
		void setTitle(const string &inp);
		void introduce() const;
	private:
		Warlock();
		Warlock(Warlock const &a);
		Warlock &operator=(Warlock const &a);

		string cName;
		string cTitle;
};

#endif
