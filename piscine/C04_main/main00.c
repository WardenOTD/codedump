#include <stdio.h>

int	ft_strlen(char *str);

int	main()
{
	char *s = "Hello World";
	int	i = ft_strlen(s);
	printf("%d\n", i);
	return 0;
}
