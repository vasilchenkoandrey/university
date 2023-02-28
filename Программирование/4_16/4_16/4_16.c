#include <stdio.h>
#include "clist.h"
#define endl printf ("\n")
#define N 21

int main () {

	PNODE nd;
	int i;
	int arr [N] = {3, 5, 54, 21, 54, 11, 3, 4, 3, 54, 54, 6, 2, 6, 12, 12, 12, 12, 4, 12, 5};

	PLIST lst = (PLIST) malloc (sizeof (LIST));
	initList (lst);

	for (i = 0; i < N; i++) {
		nd = (PNODE) malloc (sizeof (NODE));
		nd->key = i;
		nd->info = arr [i];
		insertAfter (lst, nd);
	}
	printList (lst); endl;
	deleteNeighbors (lst); endl;
	printList (lst);

	return 0;
}