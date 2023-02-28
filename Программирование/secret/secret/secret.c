#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {

	int i, j, max = 0, counterMaxValue = 0;
	unsigned long int start = 1, N = 9999999999, val;
	FILE *F;

	fopen_s(&F, "output.txt", "a");
		
	for (i = 0; i < N; i++) {
		val = start;

		printf("\nVALUE: %d\n", val);
		fprintf(F, "\nVALUE: %d\n", val);

		for (j = 0; val != 1; j++) {
			if (val % 2 == 0) {
				printf("\tY: %d/2", val);
				fprintf(F, "\tY: %d/2", val);
				val = val / 2;
				printf("=%d\n", val);
				fprintf(F, "=%d\n", val);
			}
			else {
				printf("\tN: %d*3+1", val);
				fprintf(F, "\tN: %d*3+1", val);
				val = val * 3 + 1;
				printf("=%d\n", val);
				fprintf(F, "=%d\n", val);
			}
		}
		printf("iteration = %d\n", j);
		fprintf(F, "iteration = %d\n", j);
		if (max < j) {
			max = j;
			counterMaxValue = start;
		}
		printf("MAX iteration = %d, in VALUE: %d\n", max, counterMaxValue);
		fprintf(F, "MAX iteration = %d, in VALUE: %d\n", max, counterMaxValue);
		start = 1 + rand() % 100;
	}

	return 0;
}