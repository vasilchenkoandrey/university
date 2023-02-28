#include <stdio.h>
#include <stdlib.h>
#include "tlist.h"

TREE buildTree (int n) {

	TREE root = NULL;
	int i = 0, ndLeft, ndRight;
	
	if (n>0) {
		ndRight = n / 2 - 1;
		ndLeft = n / 2 - 3;
		root = (TREE) malloc (sizeof (NODE));
		root->key = n;
		root->id = (rand () % 100) + (rand () % 23);
		root->left = buildTree (ndLeft);
		root->right = buildTree (ndRight);
	}
	return root;
}

void printTree (TREE root, int layer) {

	int i, counter = 0;

	if (root != NULL) {
		printTree (root->left, layer + 1);
		for (i = 0; i<layer; i++) {
			printf ("   ");
		}
		printf ("%d\n", root->key);
		printTree (root->right, layer + 1);
	}
}

int comparison (TREE root, TREE rootFull) {

	TREE nd = root;

	comparisonExpansion (rootFull, nd);
	if (root != NULL) {
		comparison (root->left, rootFull);
		comparison (root->right, rootFull);
	}

}

int comparisonExpansion (TREE rootFull, TREE nd) {
	
	if (rootFull != NULL) {
		if ((nd->key == rootFull->key) && (nd->id != rootFull->id))
			printf ("Element %d and %d coincide!", rootFull->key, nd->key);
		comparisonExpansion (rootFull->left, nd);
		comparisonExpansion (rootFull->right, nd);

	}

}
