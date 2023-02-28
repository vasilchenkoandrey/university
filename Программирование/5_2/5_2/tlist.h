#ifndef TLIST_H
#define TLIST_H

typedef struct NODE NODE;
typedef struct NODE* TREE;

struct NODE {
	int key, layer;
	TREE left, right;
};

TREE buildTree (int n, int layer);
void printTree (TREE root, int layer);
int countNodeInLayerTree (TREE root, int layer);

#endif