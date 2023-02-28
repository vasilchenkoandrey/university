#include <stdio.h>
#include "dlist.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int polidrom (char* word) {
	PNODE nd, nd1;
	int i = 0, j = sizeof (word), wordSize = 0;

	while (i <= j) {
		if (word [i] == word [j]) {
			i++;
			j--;
		}
		else
			break;
	}

	if (i > j)
		return 1;
	else
		return 0;
}

int main () {
	setlocale (LC_ALL, "Russian");

	PNODE nd;
	PDLIST lst;
	FILE *file;
	char word [10];
	int keyCounter = 0, i = 0;

	lst = (PDLIST) malloc (sizeof (DLIST));
	initList (lst);

	if ((file = fopen ("polidrom.txt", "r+")) == NULL)
		printf ("File not found\n");

	for (i = 0; !feof (file); i++) {
		fscanf (file, "%s", word);
		if (polidrom (word)) {
			nd = (PNODE) malloc (sizeof (NODE));
			nd->info = (char*) malloc (sizeof (char) * strlen (word) + 1);
			strcpy (nd->info, word);
			nd->key = keyCounter;
			addRight (lst, nd);
			keyCounter++;
		}
	}

	printList (lst);

	fclose (file);

	return 0;
}
