unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlen(char *str);
#include <stdio.h>
#include <string.h>
int	main()
{
	char	src[] = "Hello World";
	char	dest[] = "            ";
	unsigned int	i;

	printf("%d\n", (ft_strlen(dest)));
	printf("%d\n", (ft_strlen(src)));
	i = ft_strlcpy(dest, src, 13);
	printf("%d\n", i);
	printf("%s\n", dest);
	printf("%s\n", src);
	printf("%d\n", (ft_strlen(dest)));
	printf("%d\n", (ft_strlen(src)));
	return 0;
}
