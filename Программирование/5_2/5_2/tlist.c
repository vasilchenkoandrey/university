#include <stdio.h>
#include <stdlib.h>
#include "tlist.h"

TREE buildTree (int n, int layer) {

	TREE root = NULL;
	int ndLeft, ndRight;
	
	if (n>0) {
		ndRight = n / 2;
		ndLeft = n - ndRight - 1;
		root = (TREE) malloc (sizeof (NODE));
		root->key = n;
		root->layer = layer;
		layer++;
		root->left = buildTree (ndLeft, root->layer + 1);
		root->right = buildTree (ndRight, root->layer + 1);
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
		printf ("%d(%d)\n", root->key, root->layer);
		printTree (root->right, layer + 1);
	}
}

int count = 0;

int countNodeInLayerTree (TREE root, int layer) {

	if (root != NULL) {
		if (root->layer == layer)
			count++;
		countNodeInLayerTree (root->left, layer);
		countNodeInLayerTree (root->right, layer);
	}

	printf ("%d", count);
	return count;
}










































































//int countNodeInLayerTree (TREE root, int layer) {
//	return countNodeInLayerTreeSearch (root, layer, 1);
//}

//int countNodeInLayerTreeSearch (TREE root, int layer, int layerCount) {
//	if (root != NULL) {
//		if (layerCount == layer) {
//			return 1;
//		}
//		else if (layerCount < layer) {
//			return (countNodeInLayerTreeSearch (root->right, layer, layerCount + 1) + countNodeInLayerTreeSearch (root->left, layer, layerCount + 1));
//		}
//	}
//	return 0;
//}