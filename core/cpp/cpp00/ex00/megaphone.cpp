#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		std::string	str;
		int			j;
		int			k = 1;
		while (k < argc)
		{
			j = 0;
			while (argv[k][j])
			{
				str.append(1, toupper(argv[k][j]));
				++j;
			}
			k++;
		}
		std::cout << str << std::endl;
		return (0);
	}
	return (0);
}
