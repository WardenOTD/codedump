#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int	height = 4;
	int	width = 4;

	int	j = 0;
	int	i;
	while (j < height)
	{
		if (j == 0 || j == (height - 1))
		{
			i = 0;
			while (i < width)
			{
				printf("*");
				i++;
			}
			// for (i = 0; i < width; i++)
			// 	printf("*");
			printf("\n");
		}
		else
		{
			i = 0;
			while(i < width)
			{
				if (i == 0 || i == (width - 1))
					printf("*");
				else
					printf(" ");
				i++;
			}
			// for (i = 0; i < width; i++)
			// {
			// 	if (i == 0 || i == (width - 1))
			// 		printf("*");
			// 	else
			// 		printf(" ");
			// }
			printf("\n");
		}
		j++;
	}
	return (0);
}
