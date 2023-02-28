#include <stdio.h>
#include <stdlib.h>
#include "tlist.h"

int main () {

	TREE root;
	int layerCount = 0;
	char formula [128], formulaByTree [128];

	FILE *f = fopen ("input.txt", "r+");
	fscanf (f, "%s", formula);
	fclose (f);

	printf ("%s\n\n", formula);
	root = buildTree (15);
	printTree (root, 0);
	buildFormulaByTree (root, formulaByTree);
	printf ("\n%s\n", formulaByTree);

	return 0;
}