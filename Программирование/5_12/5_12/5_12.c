#include <stdio.h>
#include <stdlib.h>
#include "tlist.h"

int main () {

	TREE root;

	root = buildTree (15);
	printTree (root, 0);

	return 0;
}