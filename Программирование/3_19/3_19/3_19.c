#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {

	int i = 0, keyCounter = 0;
	PNODE nd, nd1, nd2;
	PLIST lst;

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

	nd1 = nd = lst->head;
	
	while (nd != lst->tail) {
		nd = nd->next;
	}
	nd->info = nd1->info;

	printList(lst);

	return 0;
}
