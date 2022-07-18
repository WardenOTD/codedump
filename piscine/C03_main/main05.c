unsigned int	ft_strlcat(char *dest, char *src,  unsigned int size);

#include <stdio.h>
#include <string.h>
int	main()
{
	char	s1[100] = "Hello ";
	char	s2[100] = "World!";
	char	s3[100] = "Hello ";
	char	s4[100] = "World!";

	unsigned int	i;
	printf("s1 : %s\ns2 : %s\n", s1, s2);
	i = ft_strlcat(s1, s2, 15);
	printf("s1 : %s\ns2 : %s\nft_strlcat : %d\n", s1, s2, i);
	printf("s3 : %s\ns4 : %s\n", s3, s4);
	unsigned int	j = strlcat(s3, s4, 15);
	printf("s3 : %s\ns4 : %s\nstrlcat : %d\n", s3, s4, j);
	return (0);
}
