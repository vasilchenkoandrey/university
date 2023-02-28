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
		printf ("%d\n", i + 1);
		printTree (root->right, layer + 1);
	}
}