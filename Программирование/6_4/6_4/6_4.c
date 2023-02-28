#include<stdio.h>
#include<stdlib.h>
#define endl printf ("\n")
#define m 5
#define n 3

int a [m] [n];
int i, j, k, l, temp;
int max [m], tmp [n];

int main () {

	printf ("Old Matrix:\n");
	for (i = 0; i<m; i++) {
		for (j = 0; j<n; j++) {
			a [i] [j] = rand () % 89 + 10;
			printf ("%5d", a [i] [j]);
		}
		endl;
	}


	for (i = 0; i<m; i++) {
		for (j = 0; j<n; j++) {
			if (max [i] < a [i] [j])
				max [i] = a [i] [j];
		}
	}

	for (k = 0; k<m - 1; k++) {
		for (l = k + 1; l<m; l++) {
			if (max [k]<max [l]) {

				for (j = 0; j<n; j++) {
					tmp [j] = a [l] [j];
					a [l] [j] = a [k] [j];
					a [k] [j] = tmp [j];

					temp = max [l];
					max [l] = max [k];
					max [k] = temp;
				}
			}
		}
	}

	endl; printf ("New Matrix:\n");
	for (i = 0; i<m; i++) {
		for (j = 0; j<n; j++) {
			printf ("%5d", a [i] [j]);
		}
		endl;
	}

	return 0;
}