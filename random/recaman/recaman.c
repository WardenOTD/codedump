#include <stdio.h>
#define MAX 100
#define BLUE "\e[0;34m"
#define RESET "\e[0m"

int main() {
	int counter = 0;
	int recaman[100] = {0};

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
	return 0;
}
