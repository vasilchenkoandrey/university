#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "dlist.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main () {
	setlocale (LC_ALL, "Russian");

	PNODE nd;
	PDLIST lst;
	FILE *file;
	char word [20];
	int keyCounter = 0, i = 0;

	lst = (PDLIST) malloc (sizeof (DLIST));
	initList (lst);

	if ((file = fopen ("GAI.txt", "r+")) == NULL)
		printf ("File not found\n");

	for (i = 0; !feof (file); i++) {
		nd = (PNODE) malloc (sizeof (NODE));
		nd->key = i + 1;

		fscanf (file, "%s", word);
		nd->number = (char*) malloc (sizeof (char) * strlen (word) + 1);
		strcpy (nd->number, word);

		fscanf (file, "%s", word);
		nd->color = (char*) malloc (sizeof (char) * strlen (word) + 1);
		strcpy (nd->color, word);

		fscanf (file, "%s", word);
		nd->year = (char*) malloc (sizeof (char) * strlen (word) + 1);
		strcpy (nd->year, word);

		fscanf (file, "%s", word);
		nd->mark = (char*) malloc (sizeof (char) * strlen (word) + 1);
		strcpy (nd->mark, word);

		fscanf (file, "%s", word);
		nd->addres = (char*) malloc (sizeof (char) * strlen (word) + 1);
		strcpy (nd->addres, word);

		addRight (lst, nd);
	}

	fclose (file);

	return 0;
}
