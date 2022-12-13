#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void	moyai(int *data)
{
	int		fd;
	fd = *data;

	long	gb = 0;
	long	total_size = 200000000;
	// 5 threads mean 5 times the work so 200mil bytes * 5 is 1bil, which is 1GB
	int		size = 4;
	// unicode characters range from 1-4 bytes, I assume moyai is 4 so I increment by 4
	while (gb < total_size)
	{
		write(fd, "\U0001F5FF", size);
		gb+=size;
	}
}

int	main()
{
	pthread_t thread_1;
	pthread_t thread_2;
	pthread_t thread_3;
	pthread_t thread_4;
	pthread_t thread_5;
	int	fd = open("moyai.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	pthread_create(&thread_1, 0, (void *)moyai, &fd);
	pthread_create(&thread_2, 0, (void *)moyai, &fd);
	pthread_create(&thread_3, 0, (void *)moyai, &fd);
	pthread_create(&thread_4, 0, (void *)moyai, &fd);
	pthread_create(&thread_5, 0, (void *)moyai, &fd);
	pthread_join(thread_1, 0);
	pthread_join(thread_2, 0);
	pthread_join(thread_3, 0);
	pthread_join(thread_4, 0);
	pthread_join(thread_5, 0);
	// gcc -lpthread moyai.c
}
