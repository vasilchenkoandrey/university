#include <stdio.h>
#include <stdlib.h>
#include "tlist.h"

int main () {

	TREE root;

	root = buildTree (25);
	printTree (root, 0);
	comparison (root, root);

	return 0;
}