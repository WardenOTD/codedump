char	*ft_strcpy(char *dest, char *src);

#include <stdio.h>
int	main()
{
	char	src[] = "Hello World\n";
	char	dest[] = "";
	printf("%s\n", dest);
	ft_strcpy(dest, src);
	printf("%s", dest);
	return (0);
}
