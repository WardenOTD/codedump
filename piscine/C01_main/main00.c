#include <stdio.h>
void	ft_ft(int *nbr);

int	main(void)
{
	int	x;
	int	*nbr;

	x = 0;
	nbr = &x;
	printf("%d\n", x);
	ft_ft(nbr);
	printf("%d\n", x);
}
