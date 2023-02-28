#include <stdio.h>
#include <stdlib.h>
#include "tlist.h"
#define SIZE 5

int main () {

	TREE root;
	char formula [SIZE] = {7, 2, 3, '+', '*'};

	root = buildTree (SIZE, *formula);
	printTree (root, 0);

	return 0;
}