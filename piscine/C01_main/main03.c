#include <stdio.h>
void	ft_div_mod(int a, int b, int *div,int *mod);

int	main(void)
{
	int	x;
	int	y;
	int	*dx;
	int	*my;

	dx = &x;
	my = &y;
	ft_div_mod(5, 10, dx, my);
	printf("div=%d\n", x);
	printf("mod=%d\n", y);
	return (0);
}
