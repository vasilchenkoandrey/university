#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {

	int i = 0, keyCounter = 0;
	PNODE nd, nd1, nd2, nd3;
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

	nd1 = lst->head;
	nd2 = lst->head;
	nd3 = lst->tail;
	
	while (nd != lst->tail) {
		nd = nd->next;
	}
	nd2->info = nd->info;


	/*while (nd != lst->tail) {
		nd1 = nd;
		nd = nd->next;
	}
	nd->next = lst->head->next;
	nd1->next = lst->head;
	lst->tail = lst->head;
	lst->head = nd;*/

	


	printList(lst);

	return 0;
}
