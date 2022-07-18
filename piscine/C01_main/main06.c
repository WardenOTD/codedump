#include <stdio.h>
int	ft_strlen(char *str);

int	main(void)
{
	char	a[] = {'H', 'E', 'L', 'L', 'O', '\n'};
	int	i;

	i = ft_strlen(a);
	printf("%d\n", i);
	return (0);
}
