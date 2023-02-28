/ dlist.h* /
#ifndef DLIST_H 
#define DLIST_H 
#define LISTSIZE 100 

typedef enum { true, false }bool;
typedef struct NODE NODE;
typedef struct DLIST DLIST;
typedef struct NODE *PNODE;
typedef struct DLIST *PDLIST;

struct NODE {
	int key;
	int info;
	PNODE prev, next;
}node;

struct DLIST {
	int count;
	int size;
	PNODE left, right;
}list;
void init_dlist (PDLIST l);
bool is_dlist_empty (PDLIST l);
bool is_dlist_overflow (PDLIST l);
void print_dlist (PDLIST l);
bool add_before_left (PDLIST l, PNODE nd);
bool add_after_right (PDLIST l, PNODE nd);
PNODE find_in_dlist (PDLIST l, int k);
bool delete_from_dlist (PDLIST l, int k);
bool insert_after (PDLIST l, PNODE nd, int k);
bool insert_before (PDLIST l, PNODE nd, int k);

#endif