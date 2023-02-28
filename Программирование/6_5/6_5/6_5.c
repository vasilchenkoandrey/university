#include<stdio.h>
#include<stdlib.h>
#define endl printf ("\n")
#define m 25

typedef enum { false, true } bool;

	int main () {

		int a [m];
		int i, j, temp;
		int res = 1;
		bool var;
		int index = 0, s, temp_massive [m];

		for (i = 0; i < m; i++) {
			a [i] = rand () % 89 + 10;
			printf ("%3d", a [i]);
		}
		endl;

		for (i = 0; i < m; i++) {
			temp = a [i];
			var = true;
			for (s = 0; (s < m) && var; s++) {
				if (temp == temp_massive [s]) 
					var = false;
				else if (s == m - 1) {
					temp_massive [index] = a [i];
					index++;
				}
			}
		}
		for (i = 0; i < index; i++) {
			a [i] = temp_massive [i];
		}

		for (i = 0; i < m; i++) {
			printf ("%3d", a [i]);
		}

		endl;
		for (i = m - 1; i >= 0; i--) {
			res = 1;
			for (j = 0; j < i; j++) {
				if (a [j] > a [j + 1]) {
					temp = a [j];
					a [j] = a [j + 1];
					a [j + 1] = temp;
					res = 0;
				}
			}
			if (res == 1)
				break;
		}


		for (i = 0; i < m; i++)
			printf ("%3d", a [i]);
		endl;

		return 0;
	}