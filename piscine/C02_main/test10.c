#include <stdio.h>
#include <string.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i=0;
	while (str[++i])
		continue ;
	return i;
}

int	main()
{
	char	src[] = "Hello World";
	char	dest[] = "            ";
	unsigned long	l;
	printf("%d\n%d\n", (ft_strlen(dest)), (ft_strlen(src)));
	l = strlcpy(dest, src, 13);
	printf("%lu\n", l);
	printf("%s\n%s\n", dest, src);
	printf("%d\n%d\n", (ft_strlen(dest)), (ft_strlen(src)));
	return 0;
}
