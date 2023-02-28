#ifndef CLIST_H
#define CLIST_H
#define LISTSIZE 100

typedef enum { false, true } bool;
typedef struct NODE NODE;
typedef struct NODE* PNODE;
typedef struct LIST LIST;
typedef struct LIST* PLIST;

struct NODE {
	int key, info;
	PNODE prev, next;
};

struct LIST {
	int count, size;
	PNODE entry;
};

void initList (PLIST lst);
bool isEmpty (PLIST lst);
bool isOverflow (PLIST lst);
void insertAfter (PLIST lst, PNODE nd);
PNODE find (PLIST lst, int k);
void delete (PLIST lst, int k);
void printList (PLIST lst);

#endif