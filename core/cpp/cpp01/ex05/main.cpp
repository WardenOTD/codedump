#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Desired level or [TEST] for infinite run mode" << std::endl;
		return (1);
	}
	else if (argc == 2)
	{
		std::string	input;
		input.assign(argv[1]);
		bool	i = 0;
		if (!input.compare("TEST"))
		{
			std::cout << "Infinite run mode enabled" << std::endl;
			i = 1;
		}
		Harl	bot;
		do
		{
			if (i)
			{
				std::cout << "\n[DEBUG] | [INFO] | [WARNING] | [ERROR] | [EXIT]" << std::endl;
				getline(std::cin, input);
				if (input.compare("DEBUG") && input.compare("INFO") && input.compare("WARNING") && input.compare("ERROR"))
				{
					if (!input.compare("EXIT"))
					{
						std::cout << "Exit Successful\n";
						return (0);
					}
					std::cout << "Invalid Input" << std::endl;
					continue ;
				}
			}
			bot.complain(input);
		}while (i);
	}
	return (0);
}
