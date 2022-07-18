#include <stdio.h>
#include <string.h>

int	main()
{
	char	src[] = "Hello World";
	char	dest[] = "alskdhjasldjkhasdkhsadk";

	printf("%s\n%s\n", src, dest);
	strncpy(dest, src, 24);
	printf("%s\n%s\n", src, dest);
	return 0;
}
