#include <stdio.h>
#include "clist.h"

#define N 10

int verification (PLIST lst) {

	PNODE nd;

	nd = lst->entry;
	do {
		if (nd->info == nd->next->info)
			printf ("[%d=%d] = [%d=%d]\n", nd->key, nd->info, nd->next->key, nd->next->info);
		nd = nd->next;
	}
	while (nd->next != lst->entry->next);

	return 0;
}

int main () {

	PNODE nd;
	int i;
	int arr [N] = {54, 54, 5, 21, 11, 11, 3, 4, 67, 54};

	PLIST lst = (PLIST) malloc (sizeof (LIST));
	initList (lst);

	for (i = 0; i < N; i++) {
		nd = (PNODE) malloc (sizeof (NODE));
		nd->key = rand () % 100;
		nd->info = arr [i];
		insertAfter (lst, nd);
	}
	printList (lst);
	verification (lst);

	return 0;
}