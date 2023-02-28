#include <stdio.h>
#include "list.h"
#define N 19

int iteration(PLIST lst) {
	int sum;
	PNODE nd, nd1;
	nd = lst->head;
	nd1 = lst->head->next->next;
	while (nd1 != NULL) {
		sum = (nd->info * nd1->info);
		printf("%d + %d = %d\n", nd->info, nd1->info, sum);
		nd = nd->next;
		nd1 = nd1->next;
	}
	return sum;
}

int main() {
	PLIST lst;
	PNODE nd;
	int i;
	lst = (PLIST)malloc(sizeof(LIST));
	initList(lst);
	for (i = 0; i<N; i++) {
		nd = (PNODE)malloc(sizeof(node));
		nd->key = i + 1;
		nd->info = rand () % 10;
		addAfterTailList(lst, nd);
	}
	printList(lst);

	iteration(lst);
	return 0;
}
