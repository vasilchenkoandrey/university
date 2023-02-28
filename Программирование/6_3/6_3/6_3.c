#include<stdio.h>
#include<stdlib.h>
#define endl printf ("\n")
#define m 5
#define n 3
#define m_val 100

int a [m] [n];
int i, j, k, l, temp;
int min [m], tmp [n];

int main () {

	for (i = 0; i<m; i++)
		min [i] = m_val + 1;

	printf ("Old Matrix:\n");
	for (i = 0; i<m; i++) {
		for (j = 0; j<n; j++) {
			a [i] [j] = rand () % m_val;
			printf ("%5d", a [i] [j]);
		}
		endl;
	}


	for (i = 0; i<m; i++) {
		for (j = 0; j<n; j++) {
			if (min [i] > a [i] [j])
				min [i] = a [i] [j];
		}
	}

	for (k = 0; k<m - 1; k++) {
		for (l = k + 1; l<m; l++) {
			if (min [k]>min [l]) {

				for (j = 0; j<n; j++) {
					tmp [j] = a [l] [j];
					a [l] [j] = a [k] [j];
					a [k] [j] = tmp [j];

					temp = min [l];
					min [l] = min [k];
					min [k] = temp;
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