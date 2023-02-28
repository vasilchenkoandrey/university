#include <stdio.h>
#include "clist.h"

#define N 10

int calculateNeighbors (PLIST lst) {

	PNODE nd;

	nd = lst->entry;
	do {
		if (nd->prev->info == nd->next->info) {
			printf (" (%d) <-|%d|-> (%d)\n", nd->prev->key, nd->key, nd->next->key);

		}
		nd = nd->next;
	}
	while (nd->next != lst->entry->next);

	return 0;
}

int main () {

	PNODE nd;
	int i;
	int arr [N] = {3, 5, 54, 21, 54, 11, 3, 4, 3, 54};

	PLIST lst = (PLIST) malloc (sizeof (LIST));
	initList (lst);

	for (i = 0; i < N; i++) {
		nd = (PNODE) malloc (sizeof (NODE));
		nd->key = i;
		nd->info = arr [i];
		insertAfter (lst, nd);
	}
	printList (lst);
	calculateNeighbors (lst);

	return 0;
}