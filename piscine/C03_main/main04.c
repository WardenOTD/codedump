char	*ft_strstr(char *str, char *to_find);
#include <stdio.h>
int	main()
{
	char	haystack[] = "Hello World!";
	char	needle[] = "";
	char	*yes;

	yes = ft_strstr(haystack, needle);
	printf("%s\n", yes);
	return 0;
}
