#include <stdio.h>
void	ft_swap(int *a, int *b);

int	main(void)
{
	int	n;
	int	m;
	int	*a;
	int	*b;

	n = 10;
	m = 5;
	a = &n;
	b = &m;
	printf("%d %d\n", n, m);
	ft_swap(a, b);
	printf("%d %d\n", n, m);
}
