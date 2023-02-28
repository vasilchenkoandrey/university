#ifndef DLIST_H
#define DLIST_H
#define endl printf ("\n")
#define LISTSIZE 100

typedef enum{false, true} bool;

typedef struct NODE NODE;
typedef struct NODE* PNODE;
typedef struct DLIST DLIST;
typedef struct DLIST* PDLIST;

struct NODE {
	int key, info;
	PNODE prev, next;
}node;

struct DLIST {
	int count, size;
	PNODE left, right;
}list;

void initList(PDLIST lst, int n);
PDLIST buildList (int n);
bool isEmpty(PDLIST lst);
bool isOverflow(PDLIST lst);
bool addLeft(PDLIST lst, PNODE nd);
bool addRight(PDLIST lst, PNODE nd);
PNODE getLeft(PDLIST lst);
PNODE getRight(PDLIST lst);
PNODE findList(PDLIST lst, int k);
bool deleteList(PDLIST lst, int k);
bool insertRight(PDLIST lst, PNODE nd, int k);
bool insertLeft(PDLIST lst, PNODE nd, int k);
void printList(PDLIST lst);
void destroy(PDLIST lst);
int iteration (PDLIST lst, int n);

#endif

