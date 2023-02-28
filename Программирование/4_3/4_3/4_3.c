#include <stdio.h>
#include "clist.h"

#define N 10
#define M 4

int gameCircle (PLIST lst) {

	PNODE nd, nd1;
	int i;

	nd = lst->entry;
	while (lst->count>1) { // ���� � ������ �� ������� 1 �������
		for (i = 1; i<M; i++) // ����������� ������ ������� �� ��������
			nd = nd->next;
		nd1 = nd; // ��������� ��������� �������
		nd = nd->next; // ��������� ���������� �������
		deleteList (lst, nd1->key); // ������� ������ �������
		printList (lst);
	}

	return 0;
}

int main () {

	PNODE nd;
	int i;

	PLIST lst = (PLIST) malloc (sizeof (LIST)); // ������ �������� ������
	initList (lst);

	for (i = 0; i < N; i++) { // ��������� �������� ������
		nd = (PNODE) malloc (sizeof (NODE));
		nd->key = i + 1; // ������ ������������� ������ ������� �������
		insertAfter (lst, nd);
	}
	printList (lst);
	gameCircle (lst);

	return 0;
}