#include <stdio.h>
#include <stdlib.h>
#include "tlist.h"

TREE buildTree (int n) {

	TREE root = NULL;
	int ndLeft, ndRight;
	
	if (n>0) {
		ndRight = n / 2;
		ndLeft = n - ndRight - 1;
		root = (TREE) malloc (sizeof (NODE));
		root->key = n;
		root->left = buildTree (ndLeft);
		root->right = buildTree (ndRight);
	}
	return root;
}

void printTree (TREE root, int layer) {

	int i;

	if (root != NULL) {
		printTree (root->left, layer + 1);
		for (i = 0; i<layer; i++) {
			printf ("   ");
		}
		printf ("%d\n", root->key);
		printTree (root->right, layer + 1);
	}
}

void printFoliage (TREE root) {

	TREE nd = root;
	int layer = 0;

	if (root != NULL) {
		printFoliage (root->left);
		if (root->key == 1)
			printf ("[%d] ", root->key);
		else
			printf ("");
		printFoliage (root->right);
	}
}