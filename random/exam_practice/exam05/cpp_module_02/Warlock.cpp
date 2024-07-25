#include "Warlock.hpp"

Warlock::Warlock(string name, string title) : cName(name), cTitle(title){
	cout << cName << ": This looks like another boring day." << endl;
}

Warlock::~Warlock(){
	cout << cName << ": My job here is done!" << endl;
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
	_SpellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string SpellName)
{
	_SpellBook.forgetSpell(SpellName);
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (_SpellBook.createSpell(SpellName))
		_SpellBook.createSpell(SpellName)->launch(target);
}
