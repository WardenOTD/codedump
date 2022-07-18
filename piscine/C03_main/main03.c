#include <stdio.h>

int	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main()
{
	char s1[25] = "abcdefghjkl";
	char s2[] = "mnopqrstuvwxyz";

	printf("%s\n%s\n", s1, s2);
	ft_strncat(s1, s2, 2);
	printf("%s\n%s\n", s1, s2);
	return 0;
}
