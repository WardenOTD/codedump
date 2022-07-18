#include <stdio.h>

int	*ft_strcat(char *dest, char *src);

int	main()
{
	char s1[25] = "abcdefghjkl";
	char s2[] = "mnopqrstuvwxyz";

	printf("%s\n%s\n", s1, s2);
	ft_strcat(s1, s2);
	printf("%s\n%s\n", s1, s2);
	return 0;
}
