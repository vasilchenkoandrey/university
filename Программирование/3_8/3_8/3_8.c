#include <stdio.h> // ���������� ���������� "stdio.h"
#include <stdlib.h> //���������� ���������� "stdlib.h"
#include "list.h" // ���������� ���������� ������� "list.h"
#define N 10 // ���������
int main(void) {  // ������� "main". "void" ������ ��, ��� ���� ������� ������ �� ������ ����������

	PLIST lst; // ������
	PNODE nd, ndMin, ndMax; // ����
	int i = 0, keyCounter = 0; // �������� � ��� �����

	lst = (PLIST)malloc(sizeof(LIST)); // �������� ������ �� ��� ������
	initList(lst); // �������������� ������

	for (; i<N; i++) {  // ���� ���������� ������ ������ �������� "N"
		nd = (PNODE)malloc(sizeof(NODE)); // �������� ������ ��� ���� "nd"
		nd->key = keyCounter; // ����������� ���� "key" ��� ������� ���� "nd". ���������� ����� �� �������� keyCounter {0..LISTSIZE - 1}
		nd->info = rand() % 100;  // ����������� �������� "info" ��� ������� ���� "nd". ���������� �������� ��������, � ������� ������� "rand"
		addBeforeHeadList(lst, nd); // ��������� ��������� � ���������� ���� "nd" � ������ ������ "lst"
		keyCounter++; // ����������� ������� ��� ���������� ������ "key" �� 1. ������ ���� +1 � �����������
	}
	printf("List:\n"); // �������� ����� "List:" � ��������� ������� �� ����� ������ � ������� "\nd"
	printList(lst); // �������� ������

	ndMax = ndMin = lst->head; // �������, ��� ����������� � ������������ �������� ������ ������� ������
	nd = lst->head->next; // �������� �������� �� ������� �������� ������
	while (nd != NULL) { // ���� �� ����� �� �����
		if (nd->info > ndMax->info) // ���� ������� ��������������� ������� ������ �������� �������������
			ndMax = nd; // ������� ������� ��������������� ������� ������� ������������
		else if (nd->info < ndMin->info) // ���� ������� ��������������� ������� ������ �������� ������������
			ndMin = nd; // ������� ������� ��������������� ������� ������� �����������
		nd = nd->next; // ��������� � ����������
	}

	nd = (PNODE)malloc(sizeof(NODE)); // �������� ������ ��� ���� "nd"
	nd->key = keyCounter; // ����������� ���� "key" ��� ������� ���� "nd". ���������� ����� �� �������� keyCounter {0..LISTSIZE - 1}
	nd->info = ndMin->info; // ����������� �������� "info" ��� ������� ���� "nd". ���������� �������� �� ���� "ndMax" - ��� ���� � ������������ ��������� "info"
	insertAfterList(lst, nd, ndMax->key); // ��������� � ����� ������ ���� "nd" � ������ "ndMax->key"
	printf("Maximal number is %d\n", ndMax->info); // �������� ���� "ndMax" � ������������ �������� "info" � ��������� ������� �� ����� ������ � ������� "\nd"
	printf("Minimal number is %d\n", ndMin->info); // �������� ���� "ndMin" � ����������� �������� "info" � ��������� ������� �� ����� ������ � ������� "\nd"
	printf("Result:\n"); // �������� ����� "Result:" � ��������� ������� �� ����� ������ � ������� "\nd"

	printList(lst); // �������� ������
	return 0; // ��������� ������ �� ����������
}


// ���������� ������ �������:)