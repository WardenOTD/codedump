#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include <map>
#include "ATarget.hpp"
#include "SpellBook.hpp"

using std::string;
using std::map;
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

		void learnSpell(ASpell* spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, ATarget const & target);
	private:
		Warlock();
		Warlock(Warlock const &a);
		Warlock &operator=(Warlock const &a);

		string cName;
		string cTitle;

		SpellBook _SpellBook;
};

#endif
