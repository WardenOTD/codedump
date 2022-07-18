#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main()
{
	char	s1[] = "abcdEf";
	char	s2[] = "abcdef";
	int	i = ft_strncmp(s1, s2, 5);
	printf("%d\n", i);
	return 0;
}
