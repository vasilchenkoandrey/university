#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main() {

	PLIST lst;
	PNODE nd, nd1, nd2, nd3, nd4;
	int i;

	lst = (PLIST)malloc(sizeof(list));
	initList(lst);

	srand(time(0));

	for (i = 0; i<LISTSIZE; i++) {
		nd = (PNODE)malloc(sizeof(node));
		nd->key = (i + 1);
		nd->info = rand(time) % 10;
		addBeforeHeadList(lst, nd);
	}
	printList(lst);

	nd = NULL;
	nd4 = NULL;
	nd1 = lst->head;
	while (nd1 != NULL) { 
		i = 1; 
		nd2 = nd1->next; 
		nd3 = nd1;
		while (nd2 != NULL) {
			if (nd2->info == nd1->info) { 
				i++;
				nd3->next = nd2->next;
				nd2->next = nd;
				if (nd == NULL) lst->tail = nd2;
				nd = nd2;
				nd2 = nd3->next;
			}
			else {
				nd3 = nd2;
				nd2 = nd2->next;
			}
		}
		if (i>1) { 
			if (nd4 == NULL) { 
				lst->head = nd1->next;
				nd1->next = nd;
				nd = nd1;
				nd1 = lst->head;
			}
			else {
				nd4->next = nd1->next;
				nd1->next = nd;
				nd = nd1;
				nd1 = nd4->next;
			}
		}
		else {
			nd4 = nd1; 
			nd1 = nd1->next;
		}
	}
	if (lst->head == NULL) lst->head = nd;
										
	else nd4->next = nd; 
	printList(lst); 
	return 0;
}
