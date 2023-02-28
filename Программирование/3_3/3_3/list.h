#ifndef LIST_H
#define LIST_H

#define LISTSIZE 100

typedef struct LIST LIST;
typedef struct LIST* PLIST;
typedef struct NODE NODE;
typedef struct NODE* PNODE;
typedef enum { false, true } bool;

struct LIST {
	int count, size;
	PNODE head, tail;
}list;

struct NODE {
	int key, info;
	PNODE next;
}node;

LIST l;

void initList(PLIST);
bool emptyList(PLIST);
bool overflowList(PLIST);

bool addBeforeHeadList(PLIST, PNODE);
bool addAfterTailList(PLIST, PNODE);
PNODE getFromTailList(PLIST);
PNODE getFromHeadList(PLIST);
PNODE findList(PLIST, int);
void insertBeforeList(PLIST, PNODE, int);
void insertAfterList(PLIST, PNODE, int);
void deleteList(PLIST, int);
void printList(PLIST);
void destroy(PLIST l);

#endif
