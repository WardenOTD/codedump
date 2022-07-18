#include <stdio.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	str[] = "abcdEFGHijkLMNopQrSTuvWxyZ";

	printf("%s\n", ft_strlowcase(str));
}
