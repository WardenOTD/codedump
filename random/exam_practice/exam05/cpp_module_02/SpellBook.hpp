#pragma once

#include <string>
#include "ASpell.hpp"
#include <map>

using std::string;
using std::map;

class SpellBook{
	private:
		SpellBook(SpellBook const &a);
		SpellBook &operator=(SpellBook const &a);
		map<string, ASpell*> _SpellBook;
	
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell* spell);
		void forgetSpell(string const &SpellName);
		ASpell* createSpell(string const &SpellName);
};
