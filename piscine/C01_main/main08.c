#include <stdio.h>
void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	tab[] = {1, 5, 3, 8, 2, 6, 7, 4, 9, 0};
	int size;
	int	i;

	size = 10;
	for (i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	ft_sort_int_tab(tab, size);
	for (i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	return (0);
}	
