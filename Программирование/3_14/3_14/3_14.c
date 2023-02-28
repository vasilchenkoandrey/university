#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {

	int i = 0, keyCounter = 0, res = 0;
	PNODE nd, nd1;
	PLIST lst;

	lst = (PLIST)malloc(sizeof(LIST));
	initList(lst);


	for (; i<LISTSIZE; i++) {
		nd = (PNODE)malloc(sizeof(NODE));
		nd->key = keyCounter;
		nd->info = rand() % 100;
		addAfterTailList(lst, nd);
		keyCounter++;
	}

	printf("List:\n");
	printList(lst);

	nd = lst->head;
	nd1 = lst->head;
	while (nd != lst->tail) {
		nd1 = nd;
		nd = nd->next;
	}
	res = nd->info + nd1->info;
	printf("%d+%d=%d\n", nd->info, nd1->info, res);


	return 0;
}
