#include <stdio.h>
void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	tab[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
				'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int	size;
	int	i;

	size = 20;
	i = 0;
	while (i < size)
	{
		printf("%c ", tab[i]);
		i++;
	}
	printf("\n");
	ft_rev_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%c ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
