#include "Warlock.hpp"

Warlock::Warlock(string name, string title) : cName(name), cTitle(title){
	cout << cName << ": This looks like another boring day." << endl;
}

Warlock::~Warlock(){
	cout << cName << ": My job here is done!" << endl;
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
		delete it->second;
	}
	_SpellBook.clear();
}

void Warlock::introduce() const{
	cout << cName << ": I am " << cName << ", " << cTitle << "!" << endl;
}

Warlock::Warlock(){
}

Warlock::Warlock(Warlock const &a){
	*this = a;
}

Warlock &Warlock::operator=(Warlock const &a){
	this->cName = a.cName;
	this->cTitle = a.cTitle;
	return (*this);
}

string const &Warlock::getName() const{
	return (cName);
}

string const &Warlock::getTitle() const{
	return (cTitle);
}

void Warlock::setTitle(const string &inp){
	cTitle = inp;
}

void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string SpellName)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(SpellName));
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook[SpellName]->launch(target);
}
