#include <stdio.h>
#include "list.h"
#define N 20

int main(void) {
	PLIST lstStart, lstPositive, lstNegative;
	PNODE nd, nd1;
	int i = 0, keyCounter = 0, keyCounter2 = 0;

	lstStart = (PLIST)malloc(sizeof(LIST));
	lstPositive = (PLIST)malloc(sizeof(LIST));
	lstNegative = (PLIST)malloc(sizeof(LIST));

	initList(lstStart);
	initList(lstPositive);
	initList(lstNegative);
	
	for (i = 0; i<N; i++) {
		nd = (PNODE)malloc(sizeof(NODE));
		nd->key = keyCounter;
		nd->info = 5 - rand() % 10;
		addBeforeHeadList(lstStart, nd);
		keyCounter++;
	}
	printf("List:\n");
	printList(lstStart);

	nd = lstStart->head;
	keyCounter = 0;
	for (i = 0; nd != NULL; i++) {
		nd1 = (PNODE)malloc(sizeof(node));
		if (nd->info < 0) {
			nd1->key = keyCounter;
			nd1->info = nd->info;
			addBeforeHeadList(lstNegative, nd1);
			keyCounter++;
		}
		else {
			nd1->key = keyCounter2;
			nd1->info = nd->info;
			addBeforeHeadList(lstPositive, nd1);
			keyCounter2++;
		}
		nd = nd->next;
	}
	

	printf("Positive List:\n");
	printList(lstPositive);
	printf("Negative List:\n");
	printList(lstNegative);
	

	return 0;
}