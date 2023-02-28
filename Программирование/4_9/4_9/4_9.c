#include <stdio.h>
#include "dlist.h"
#include <stdlib.h>
#define N 9

int main() {
	PNODE nd;
	PDLIST lst;
	int i, j = 0, keyCounter = 0;
	int deckCard[] = { 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	lst = (PDLIST)malloc(sizeof(DLIST));
	initList(lst);

	for (i = 0; i < N; i++) {
		nd = (PNODE)malloc(sizeof(NODE));
		nd->key = keyCounter;
		nd->info = deckCard[i];
		addLeft(lst, nd);
		keyCounter++;
	}
	printList(lst);

	return 0;
}