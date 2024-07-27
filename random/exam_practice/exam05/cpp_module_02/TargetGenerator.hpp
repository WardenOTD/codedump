#pragma once
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private :
		TargetGenerator(TargetGenerator const & src);
		TargetGenerator & operator=(TargetGenerator const & src);

		std::map < std::string, ATarget*> _target;

	public :
		TargetGenerator();
		~TargetGenerator();
		
		void learnTargetType(ATarget*target);
		void forgetTargetType(std::string const &target);
		ATarget* createTarget(std::string const &target);
};
