#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main()
{
	char	src[] = "Hello World";
	char	dest[] = "aksjdhjfghmcvnmfhjkjhg";

	ft_strncpy(dest, src, 23);
	printf("%s", dest);
}
