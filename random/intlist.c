/* learning how integer arrays work */
/* Trying to sort integer arrays of size 10, random numbers shall be used,
	also jogging my memory on malloc */

#include <stdio.h>
#include <stdlib.h>

int	*intlist(int size);
void	sortlist(int *array, int size);

int	*intlist(int size)
{
	srand(424);	//424 is the sum of ascii value for the word "pain"
	int	*array = (int *)malloc(size * sizeof(int));
	int	i = 0;
	int	R;
	for (i = 0; i < size; i++)
	{
		R = rand() % 1000;	// %1000 is to set scope to 0 ~~ 999
		array[i] = R;
	}
	sortlist(array, size);
	return (array);
}

void	sortlist(int *array, int size)
{
	int	temp;
	int	count = 0;
	int i = 0;
	while (count != size - 1)
	{
		if (i == size - 1 && count != size - 1)
		{
			count = 0;
			i = 0;
			continue;
		}
		else if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i++;
		}
		else if (array[i] < array[i + 1] || array[i] == array[i + 1])
		{
			count++;
			i++;
		}
	}
}

int	main(void)
{
	int	size = 10;
	int *array = intlist(size);
	for (int i = 0; i < (size * 2); i++)	// i < (size * 2) is to show memory block incase they got sucked up by sortlist
	{
		printf("%d, ", array[i]);
	}
}
