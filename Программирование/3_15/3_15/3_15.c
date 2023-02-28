#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define N 10

bool is_in_list(PLIST lst, PNODE nd) {
	PNODE nd1;
	nd1 = lst->head;
	while ((nd1 != NULL) && ((nd->key != nd1->key) || (nd->info != nd1->info))) {
		nd1 = nd1->next;
	}
	return (nd1 != NULL) ? true : false;
}

int main(void) {
	PLIST lst, lst1;
	PNODE nd, nd1;
	int i = 0, keyCounter = 0, res = 0;

	lst = (PLIST)malloc(sizeof(LIST));
	lst1 = (PLIST)malloc(sizeof(LIST));
	initList(lst);
	initList(lst1);

	for (i = 0; i<N; i++) {
		nd = (PNODE)malloc(sizeof(NODE));
		nd->key = keyCounter;
		nd->info = rand() % 100;
		addBeforeHeadList(lst, nd);
		keyCounter++;
	}
	printf("List:\n");
	printList(lst);

	keyCounter = 0;
	for (i = 0; i<N; i++) {
		nd = (PNODE)malloc(sizeof(NODE));
		nd->key = keyCounter;
		nd->info = rand() % 100;
		addBeforeHeadList(lst1, nd);
		keyCounter++;
	}
	printf("List:\n");
	printList(lst1);

	nd = lst->head;
	nd1 = lst1->head;
	while (nd1 != NULL) {
		if (is_in_list(lst1, nd1))
			printf("[%d-%d] ", nd->info, nd->key);
			res++;
		nd1 = nd1->next;
		if (lst->count == res)
			printf("\nOK");
	}

	return 0;
}
