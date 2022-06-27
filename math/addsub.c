#include <stdio.h>

float	add(float base, float i)
{
	return (base += i);
}

float	sub(float base, float i)
{
	return (base -= i);
}

int	main()
{
	float	add1 = 50.98;
	float	add2 = 90.379;
	float	sub1 = 327.89;
	float	sub2 = 28.998;
	printf("Addition = %f\nSubtraction = %f", add(add1, add2), sub(sub1, sub2));
	return (0);
}
