#include <stdio.h>

int	fact_recur(int base)
{
	if (base == 0)
		return (1);
	else if (base > 0)
	{
		return (base * fact_recur(base - 1));
	}
}

int	power_recur(int base, int pow)
{
	if (pow <= 0)
		return (1);
	else if (pow > 0)
	{
		return (base * power_recur(base, --pow));
	}
}

int	main(void)
{
	int	base = 8;
	int	pow = 0;
	printf("%d\n%d\n", fact_recur(base), power_recur(base, pow));
	return (0);
}
