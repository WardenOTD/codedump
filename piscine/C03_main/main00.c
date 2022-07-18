int	ft_strcmp(char *s1, char *s2);
#include <stdio.h>
int	main()
{
	char	s1[] = "abcdef";
	char	s2[] = "abcDef";
	int	i;

	i = ft_strcmp(s1, s2);
	printf("%d\n", i);
	return 0;
}
