#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
	PLIST lst, lst1;
	PNODE nd;
	int i = 0, keyCounter = 0;
	lst = (PLIST)malloc(sizeof(LIST));
	initList(lst);

	for (; i<LISTSIZE; i++) {
		nd = (PNODE)malloc(sizeof(NODE));
		nd->key = keyCounter;
		nd->info = rand() % 100;
		addBeforeHeadList(lst, nd);
		keyCounter++;
	}
	printf("List:\n");
	printList(lst);

	for (i = 0; i<LISTSIZE; i++)
		if (findList(lst, i)->info % 2 == 0)
			deleteList(lst, i);

	printf("\nRemoved the even numbers:\n");
	printList(lst);
	return 0;
}
