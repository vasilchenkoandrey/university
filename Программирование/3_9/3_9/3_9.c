#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "list.h"
#define N 10

int main () {

	PLIST lst;
	PNODE nd, nd1;
	FILE *input;
	int k;
	char ch;

	lst = (PLIST) malloc (sizeof (list));
	initList (lst);

	if ((input = fopen ("input.txt", "r")) == NULL) {
		printf ("Not find file: input.txt\n");
		exit (1);
	}

	while ((ch = fgetc (input)) != EOF) {
		k = ch;
		nd1 = findList (lst, k);

		if (nd1 == NULL) {
			nd = (PNODE) malloc (sizeof (node));
			nd->key = k;
			nd->info = 1;
			addAfterTailList (lst, nd);
		}
		
		else nd1->info++;
	}

	nd = lst->head;
	while (nd != NULL) {
		printf ("((%c)-(%d)) -> ", nd->key, nd->info);
		nd = nd->next;
	}

	return 0;
	_getch ();
	system ("pause");
}
