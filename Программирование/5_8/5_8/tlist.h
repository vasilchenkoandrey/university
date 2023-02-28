#ifndef TLIST_H
#define TLIST_H

typedef struct NODE NODE;
typedef struct NODE* TREE;

struct NODE {
	int key;
	TREE left, right;
};

TREE buildTree (int);
void printTree (TREE, int);
void printFoliage (TREE);

#endif