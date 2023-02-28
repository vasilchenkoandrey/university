#include <stdio.h>
#include "dlist.h"
#include <stdlib.h>
#include <time.h>

int main() {
	int n = 15;
	PDLIST lst = buildList (n);
	printList(lst, n);
	endl;
	iteration (lst, n);

	return 0;
}