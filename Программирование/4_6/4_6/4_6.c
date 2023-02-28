#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"
#include <locale.h>


int main(void) {
	setlocale(LC_ALL, ".65001");
	PDLIST lst;
	PNODE nd;
	int i = 0, k = 0, counter = 0;

	lst = (PDLIST)malloc(sizeof(DLIST));
	initList(lst);

	while (counter < 36) {
		i = rand() % 4;
		k = rand() % 9 + 6;
		nd = findList(lst, k, i);
		if (nd == NULL) {
			nd = (PNODE)malloc(sizeof(DLIST));
			nd->key = k;
			nd->info = i;
			addLeft(lst, nd);
			counter++;
		}
	}
	deleteList(lst, 6);
	LINUX_printList (lst);

	return 0;
}
