#include <stdio.h>
void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	x;
	int	y;
	int	*a;
	int	*b;

	x = 5;
	y = 10;
	a = &x;
	b = &y;
	printf("og = %d %d\n", x, y);
	ft_ultimate_div_mod(a, b);
	printf("div: %d,  mod: %d\n", x, y);
	return (0);
}
