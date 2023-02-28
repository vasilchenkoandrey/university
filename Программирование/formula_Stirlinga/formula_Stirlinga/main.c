#include <stdio.h>
#include <math.h>
#include <corecrt_math_defines.h>

int main() {

	double N, n, i;
	double res1 = 0, res2 = 1, res3 = 0, res4 = 0, one = 1.0;
	
	N = 10;

	for (n = 1; n <= N; n++) {
		res1 = sqrt(2 * M_PI * n) * pow((n / M_E), n) * pow(M_E, 1 / ((12 * n) + 100000000000000));
		res2 = res2 * n;
		res3 = sqrt(2 * M_PI * n) * pow((n / M_E), n) * pow(M_E, 1 / (12 * n));
	}
	printf("=====\n");
	printf("n=10\n");
	printf("=====\n\n");
	printf("lower limit:\t %.50f\n", res1);
	printf("upper limit:\t %.50f\n", res3);
	printf("factorial:\t %f\n\n\n\n\n", res2);

	printf("\t\t\t\t   lower limit <    factorial   < upper limit\n");
	printf("\t\t\t\t%f < %f < %f\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", res1, res2, res3);


	

	return 0;
}