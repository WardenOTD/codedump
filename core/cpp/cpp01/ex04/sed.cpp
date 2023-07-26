#include "sed.hpp"

void	Filer::init(std::string s1, std::string s2)
{
	needle.assign(s1);
	repl.assign(s2);
}

void	Filer::getHaystack(std::ifstream &file)
{
	std::string	line;
	while (getline(file, line))
		haystack.append(line).append("\n");
}

int	Filer::findNeedle()
{
	std::size_t	id = 0;
	std::size_t	found = 0;
	if (!needle.length())
	{
		std::string	tmp;
		std::cout << "Warning: searching for |nothing| to replace.\n[Continue?] <y/n>: ";
		getline(std::cin, tmp);
		if (!tmp.compare("y"))
			found = -1;
		else
		{
			std::cout << "Successful Abort." << std::endl;
			return (0);
		}
	}
	while (id < haystack.length())
	{
		if (found != std::string::npos)
			found = haystack.find(needle, id);
		if (id == found)
		{
			haystack_repl.append(repl);
			id += needle.length();
		}
		else
		{
			haystack_repl.append(haystack, id, 1);
			id++;
		}
	}
	return (1);
}

void	Filer::copyToRepl(std::ofstream &file_repl)
{
		file_repl << haystack_repl;
}
