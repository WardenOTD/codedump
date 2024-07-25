#ifndef ASPELL_HPP
#define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

using std::string;
using std::cout;
using std::endl;

class ATarget;

class ASpell{
	protected:
		string sName;
		string sEffects;
	public:
		ASpell(std::string name, std::string effects);
		ASpell & operator=(ASpell const & a);
		ASpell(ASpell const & a);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(ATarget const & target) const;
};

#endif
