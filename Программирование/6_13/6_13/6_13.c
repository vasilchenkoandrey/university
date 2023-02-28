#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 30

void main () {

	setlocale (LC_ALL, "russian");

	int arr [N];
	int i, j, k, p, temp1;

	printf (" 13.���� ������������� �������������� ����� A1, A2,..., An, ����������� ����� k � �������������� ����� P. ������� ������� � ������� k � �������� � ������������������ P, ���, ����� ��������������� �� ����������. \n\n");
	printf ("\n ���������� ��������� � �������� ����������, � ������� �������� ������� ������������������ ��������������� �� ������, � ������ ����� ����������� ������� ����������� � ���������� ����� ����� ����� ������������� ���������. \n�������� ������������� ��������� ���������� ��������� �������� ����������� ����������� ������ �� ���� ��� ���������.\n\n\n\n");
	printf ("\n ��������: \n 1) ������� ������������� ������ ������� N.\n 2) �������� ����� ���������� �������� � �����\n    ������� ���������� �������� � ������.\n 3) �������� ������� ������� ���������� �������\n    �� ������� ������� ���������� ��������.\n 4) ���������� ������� ����� ���������� '���������'.\n\n\n");
	
	printf (" ����� ���������� �������� � ������� [0..29]: ");
	scanf ("%d", &k);
	while (k < 0 || k > 29) {
		if (k < 0 || k > 29) {
			printf (" ��������� ������� �� ������! ���������� ������ ������ ��������.\n ����� ���������� �������� � ������� [0..29]:  ");
			scanf ("%d", &k);
		}
	}

	printf (" ����� ������� ���������� �������� � ������: ");
	scanf ("%d", &p);

	printf ("\n �������� �������:\n [");
	for (i = 0; i < N; i++) {
		arr [i] = i;
		printf (" %d", arr [i]);
	}
	printf (" ]\n");

	arr [k] = p;
	for (i = 1; i < N; i++) {
		temp1 = arr [i];
		for (j = i - 1; (j >= 0) && (temp1 < arr [j]); j--) {
			arr [j + 1] = arr [j];
			arr [j] = temp1;
		}
	}

	printf ("\n ������� ���������:\n [");
	for (i = 0; i < N; i++) {
		printf (" %d", arr [i]);
	}
	printf (" ]\n\n\n");

}