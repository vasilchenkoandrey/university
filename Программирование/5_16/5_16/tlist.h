#ifndef TLIST_H
#define TLIST_H

typedef struct NODE NODE;
typedef struct NODE* TREE;

struct NODE {
	int key;
	int id;
	TREE left, right;
};

TREE buildTree (int n, char formula);
void printTree (TREE root, int layer);

#endif