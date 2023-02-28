#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 6

void main () {

	setlocale (LC_ALL, "russian");

	int arr [N] [N];
	int sum [N];
	int row, col, i, j, k, temp, next;

	printf (" 2. ���� �������������� ������� �������� m * n; ����������� (�����������) ������ ������� �� ������������� ���� ��������� �����. ����������� ������������ �������������� ������. \n\n");
	printf (" C��������� ��������� � ������� �������� ����������. �������� ��������� ������� � ����������� �� ����������� ��� ������� ����������, ������ ���� �� �������� ����������� ����� ����������� ��������� ����������. �������� ������� � ������������� �������� �� ������������ �������. �� ������ �������� ��������������� ������������ �������� ��������, �, ���� ������� � ���� ��������, �� �������� ������ �������. �� ������ ������ �� ������� ��� ������� ���� ������� ������ �� ���� �����, ������� ���������� ��������� �� ����� n-1 ��������, ��� n ������ �������, ����� ������������� ������.\n\n\n");
	printf (" ��������: \n 1) ������ ������� %d*%d � ��������� ���������� �������.\n 2) ���� ����� ����� �������.\n 3) ��������� ������� ������� '������'.\n\n\n", N, N);

	printf ("\n �������� �������: \n");
	for (i = 0; i < N; i++) {
		sum [i] = 0;
		for (j = 0; j < N; j++) {
			arr [i] [j] = rand () % 10;
			sum [i] = sum [i] + arr [i] [j];
			printf ("%2d", arr [i] [j]);
		}
		printf (" = %d\n", sum[i]);
	}
	
	k = 0;
	temp = 0;

	for (next = 1; next < N; next++) {
		for (i = 0; i < N; i++) {
			if (sum [i] < sum [i + 1]) {
				temp = sum [i];
				sum [i] = sum [i + 1];
				sum [i + 1] = temp;
				for (k = 0; k < N; k++) {
					temp = arr [i] [k];
					arr [i] [k] = arr [i + 1] [k];
					arr [i + 1] [k] = temp;
				}
			}
		}
	}
	printf ("\n");

	printf ("\n ���������� ������� '������':\n");
	for (i = 0; i < N; i++) {
		sum [i] = 0;
		for (j = 0; j < N; j++) {
			sum [i] = sum [i] + arr [i] [j];
			printf ("%2d", arr [i] [j]);
		}
		printf (" = %d\n", sum [i]);
	}
	printf ("\n");

}