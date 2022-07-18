#include <stdio.h>

int	ft_atoi(char *str);

int	main()
{
	char	*s = " 	-+++---+--+-214748dasdi3648";
	int	i = ft_atoi(s);
	printf("- %d\n", i);
	printf("0 %d\n", ft_atoi(""));
	printf("0 %d\n", ft_atoi("a"));
	printf("+ %d\n", ft_atoi("12312"));
	printf("- %d\n", ft_atoi("-12312"));
	printf("0 %d\n", ft_atoi("--wada+-12312"));
	printf("0 %d\n", ft_atoi("wadawd-12312"));
	printf("- %d\n", ft_atoi("-12awdawd312"));
	printf("- %d\n", ft_atoi("-+++12312"));
	printf("+ %d\n", ft_atoi("--12312"));
	printf("- %d\n", ft_atoi("   --+-12312"));
	printf("0 %d\n", ft_atoi(" - 12312"));
	return 0;
}
