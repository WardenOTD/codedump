#ifndef ATARGET_HPP
#define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

using std::string;
using std::cout;
using std::endl;

class ASpell;

class ATarget{
	protected:
		string tType;

	public:
		ATarget(std::string type);
		ATarget & operator=(ATarget const & rhs);
		ATarget(ATarget const & obj);
		virtual ~ATarget();
		std::string getType() const;
		virtual ATarget* clone() const = 0;
		void	getHitBySpell(ASpell const & spell) const;
};

#endif
