#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main()
{
	char	str[] = "ajsdhas 102983123@!@#$%&";
	
	printf("%d\n", ft_str_is_printable(str));
}
