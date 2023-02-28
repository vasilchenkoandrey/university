#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "dlist.h"
#include <string.h>
#include <stdlib.h>

cryption(PDLIST lst, PNODE nd, char *word, int select) {

	int i;
	char ch;
	bool res;

	for (i = 0; i < strlen(word); i++) {
		res = false;
		ch = word [i];
		nd = lst->left;
		while (nd != NULL) {
			if (select == 1) {
				if (ch == nd->info) {
					ch = nd->key;
					word [i] = ch;
					res = true;
				}
			}

			else {
				if (ch == nd->key) {
					ch = nd->info;
					word [i] = ch;
					res = true;
				}
			}

			if (res == true) break;
			nd = nd->next;
		}
	}
	
	return word;
}

int main() {
	FILE *GE, *DE, *EN;
	PNODE nd;
	PDLIST lst;
	char word [20];
	char alphabet [2] [52] = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
						  	    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
								'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
								'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
							   {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'A', 'S', 'D',
								'F', 'G', 'H', 'J', 'K', 'L', 'z', 'x', 'c', 'v', 'b', 'n', 'm',
								'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'a', 's', 'd',
								'f', 'g', 'h', 'j', 'k', 'l', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'} };
	int select, i;

	GE = fopen("general.txt", "r+");
	DE = fopen("decryption.txt", "r+");
	EN = fopen("encryption.txt", "r+");

	lst = (PDLIST)malloc(sizeof(DLIST));
	initList(lst);

	for (i = 0; i < 52; i++) {
		nd = (PNODE) malloc (sizeof (NODE));
		nd->info = alphabet [0] [i];
		nd->key = alphabet [1] [i];
		addRight (lst, nd);
	}

	printf("Entry 1 or 2\n\n1) Encryption\n2) Decryption\n");
	scanf("%d", &select);

	nd = lst->left;

	switch (select) {
		case 1: {
			for (i = 0; !feof (GE); i++) {
				fscanf (GE, "%s", word);
				cryption (lst, nd, word, select);
				fprintf (EN, "%s ", word);
			};
		}break;

		case 2: {
			for (i = 0; !feof (EN); i++) {
				fscanf (EN, "%s", word);
				cryption (lst, nd, word, select);
				fprintf (DE, "%s ", word);
			};
		}break;
	}

	fclose(EN);
	fclose(DE);
	fclose(GE);

	return 0;
}
