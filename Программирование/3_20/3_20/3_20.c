#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <conio.h>
#define N 5

int main () {

	PLIST lst1, lst2;
	PNODE nd, nd1;
	int c, i;

	lst1 = (PLIST) malloc (sizeof (list));
	initList (lst1);

	for (i = 0; i<N; i++) {
		nd = (PNODE) malloc (sizeof (node));
		nd->key = i + 1;
		nd->info = rand () % 10;
		addBeforeHeadList (lst1, nd);
	}
	printf ("List 1:\n");
	printList (lst1);

	lst2 = (PLIST) malloc (sizeof (list));
	initList (lst2);

	for (i = 0; i<N; i++) {
		nd = (PNODE) malloc (sizeof (node));
		nd->key = i + 1;
		nd->info = rand () % 10;
		addBeforeHeadList (lst2, nd);
	}
	printf ("List 2:\n");
	printList (lst2);

	c = rand () % 5;
	printf ("C = %d\n\n", c);
	nd1 = findList (lst1, c);

	if (nd1 != NULL) {
		lst2->tail->next = nd1->next;
		nd1->next = lst2->head;
	}
	printf ("Converted list %d\n", c);
	printList (lst1);

	system ("pause");
	_getch ();
	return 0;
}
