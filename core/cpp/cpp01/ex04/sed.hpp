#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <string>
# include <fstream>

class Filer{
	public:
		void	init(std::string s1, std::string s2);
		void	getHaystack(std::ifstream &file);
		int		findNeedle();
		void	copyToRepl(std::ofstream &file_repl);
	private:
		std::string	haystack;
		std::string	haystack_repl;
		std::string	needle;
		std::string	repl;
};

#endif
