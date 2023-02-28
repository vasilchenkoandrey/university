#include <stdio.h>
#include "dlist.h"
#include <stdlib.h>
#include <time.h>
#define N 6

int main() {
	PNODE nd, nd1;
	PDLIST lst;
	int i, keyCounter = 0;
	int res;

	srand(time(NULL));

	lst = (PDLIST)malloc(sizeof(DLIST));
	initList(lst);

	for (i = 0; i < N; i++) {
		nd = (PNODE)malloc(sizeof(NODE));
		nd->key = keyCounter;
		nd->info = 1 + rand() % 9;
		addLeft(lst, nd);
		keyCounter++;
	}
	printList(lst);
	printf("\n");

	return 0;
}