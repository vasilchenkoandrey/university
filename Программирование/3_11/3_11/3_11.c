#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define N 10

int main () {

	PLIST lst;
	PNODE nd, nd1, nd2, nd3, nd4;
	int i;

	lst = (PLIST) malloc (sizeof (list));
	initList (lst);

	for (i = 0; i<N; i++) { // ��������� ������
		nd = (PNODE) malloc (sizeof (node));
		nd->key = i + 1;
		nd->info = rand () % 10 + 10;
		addAfterTailList (lst, nd);
	}
	printList (lst); //�������� �������� ������

	nd1 = lst->head; // ������� �������������� �������
	nd2 = NULL; // ��������� �� "����� ������"
	nd4 = NULL; // ��������� �� ���������� �������
	while (nd1 != NULL) { // ���� �� ����� �� ����� ������

		if (nd1->info % 2 == 1) { //���� ����� ��������
			if (nd4 == NULL) lst->head = nd1->next; //���� �� ������, �������� ������
			else nd4->next = nd1->next; // ����� ������������� ������ ����� ���� (������� �� ������)
			nd3 = nd1->next; // ���������� ��������� �� ��������������
			if (nd2 == NULL) lst->tail = nd1; // ���� ��� ������ �����������, �� ���� ������� ����� ������� ������ ������
			nd1->next = nd2; // ����������� ������� � "����� ������"
			nd2 = nd1;// �� ����� ����� ������� "����� ������"
			nd1 = nd3; //������� �������������� ������� - ��� ����������� ���������
		}

		else { // ���� ����� ������
			nd4 = nd1; // ������� ���������� ����������
			nd1 = nd1->next; // ��������� � ����������
		}
	}

	if (nd4 == NULL) lst->head = nd2; // ���� ��� ��������� � "����� ������", �� ��� ������ ����� ������� ���������� ������
	else nd4->next = nd2; // ����� ����������� "����� ������"

	printList (lst); //�������� ���������

	return 0;
}
