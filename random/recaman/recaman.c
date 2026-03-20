#include <stdio.h>
#include <stdlib.h>
// #define MAX 100
#define BLUE "\e[0;34m"
#define RESET "\e[0m"

int main(int argc, char **argv) {
	int MAX = 100;
	if (argc > 1)
		MAX = atoi(argv[1]);
	int counter = 0;
	int *recaman = malloc(MAX * sizeof(int));
	if (recaman == NULL) {
		fprintf(stderr, "Malloc Error\n");
		return 1;
	}
	recaman[0] = 0;

	for (counter; counter < MAX; counter++){
		if (counter == 0)
			recaman[counter] = 0;
		else if (recaman[counter - 1] - counter > 0) {
			int i;
			for (i = 0; i < counter; i++) {
				if (recaman[counter - 1] - counter == recaman[i]) {
					recaman[counter] = recaman[counter - 1] + counter;
					break;
				}
			}
			if (i == counter)
				recaman[counter] = recaman[counter - 1] - counter;
		}
		else
			recaman[counter] = recaman[counter - 1] + counter;
	}
	for (counter = 0; counter < MAX; counter++){
		printf("%s%d%s", BLUE, recaman[counter], RESET);
		if (counter < MAX - 1)
			printf(", ");
		else
			printf("\n");
	}
	free(recaman);
	return 0;
}
