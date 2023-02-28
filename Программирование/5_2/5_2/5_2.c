#include <stdio.h>
#include <stdlib.h>
#include "tlist.h"

int main () {

	TREE root;

	root = buildTree (15, 1);
	printTree (root, 0);
	countNodeInLayerTree (root, 4);

	return 0;
}