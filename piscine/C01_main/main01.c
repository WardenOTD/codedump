#include <stdio.h>
void	ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int	a;
	int	*pt1;
	int	**pt2;
	int	***pt3;
	int	****pt4;
	int	*****pt5;
	int	******pt6;
	int	*******pt7;
	int	********pt8;
	int	*********pt9;

	a = 100;
	pt1 = &a;
	pt2 = &pt1;
	pt3 = &pt2;
	pt4 = &pt3;
	pt5 = &pt4;
	pt6 = &pt5;
	pt7 = &pt6;
	pt8 = &pt7;
	pt9 = &pt8;

	printf("%d\n", a);
	ft_ultimate_ft(pt9);
	printf("%d\n", a);
	return (0);
}
