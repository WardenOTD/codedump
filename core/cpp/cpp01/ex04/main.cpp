#include "sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "FILENAME, S1, S2\n";
		return (1);
	}
	if (argc == 4)
	{
		Filer		SnR;
		std::ifstream	file;
		std::ofstream	file_repl;
		std::string	filename;
		std::string	filename_repl;
		std::string	s1;
		std::string	s2;

		filename.assign(argv[1]);
		filename_repl.assign(filename).append(".replace");
		s1.assign(argv[2]);
		s2.assign(argv[3]);

		file.open(filename, std::ios::in);
		if (!file)
		{
			std::cout << "FILE DOES NOT EXIST\n";
			file.close();
			return (1);
		}
		file_repl.open(filename_repl, std::ios::out | std::ios::trunc);
		SnR.init(s1, s2);
		SnR.getHaystack(file);
		if (!SnR.findNeedle())
		{
			file.close();
			file_repl.close();
			return (1);
		}
		SnR.copyToRepl(file_repl);
		file.close();
		file_repl.close();
	}
	return (0);
}
