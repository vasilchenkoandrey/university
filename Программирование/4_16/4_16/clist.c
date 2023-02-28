#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

void initList (PLIST lst) {
	lst->count = 0;
	lst->size = LISTSIZE;
	lst->entry = NULL;
}

bool isEmpty (PLIST lst) {
	return lst->count == 0;
}

bool isOverflow (PLIST lst) {
	return lst->count == lst->size;
}

void printList (PLIST lst) {
	PNODE nd;
	nd = lst->entry;
	if (!isEmpty (lst)) {
		if (nd->next != lst->entry) printf ("[%d=%d] -> ", nd->key, nd->info);
		else printf ("[%d=%d]", nd->key, nd->info);
		nd = nd->next;
		while (nd->next != lst->entry->next) {
			if (nd->next != lst->entry) printf ("[%d=%d] -> ", nd->key, nd->info);
			else printf ("[%d=%d]", nd->key, nd->info);
			nd = nd->next;
		}
	}
	printf ("\n");
}

void insertAfter (PLIST lst, PNODE nd) {
	if (!isOverflow (lst)) {
		if (isEmpty (lst)) {
			lst->entry = nd;
			lst->count = 1;
			nd->next = nd->prev = nd;
		}
		else if (lst->count == 1) {
			nd->next = nd->prev = lst->entry;
			lst->entry->next = lst->entry->prev = nd;
			lst->count++;
		}
		else {
			nd->next = lst->entry;
			lst->entry->prev->next = nd;
			nd->prev = lst->entry->prev;
			lst->entry->prev = nd;
			lst->count++;
		}
	}
}

PNODE find (PLIST lst, int k) {
	PNODE nd = NULL;
	if (!isEmpty (lst)) {
		nd = lst->entry;
		while ((nd->next != lst->entry) && nd->key != k) {
			nd = nd->next;
		}
	}
	return nd;
}

int deleteNeighbors (PLIST lst) {

	PNODE nd;

	nd = lst->entry;
	do {
		if (nd->prev->info == nd->next->info) {
			printf ("Neighbors [%d=%d] and [%d=%d] deleted\n", nd->prev->key, nd->prev->info, nd->next->key, nd->next->info);
			delete (lst, nd->prev->key); 
			delete (lst, nd->next->key);
		}
		nd = nd->next;
	}
	while (nd->next != lst->entry->next);

	return 0;
}

void delete (PLIST lst, int k) {
	PNODE nd;
	nd = find (lst, k);
	if (nd != NULL) {
		if (lst->count == 1) {
			initList (lst);
		}
		else if (lst->count == 2) {
			if (nd == lst->entry) {
				lst->entry = lst->entry->next;
				lst->count = 1;
				lst->entry->next = lst->entry->prev = lst->entry;
			}
			else {
				lst->count = 1;
				lst->entry->next = lst->entry->prev = lst->entry;
			}
		}
		else {
			if (nd == lst->entry) {
				lst->entry->prev->next = nd->next;
				nd->next->prev = lst->entry->prev;
				lst->count--;
				lst->entry = nd->next;
			}
			else {
				nd->prev->next = nd->next;
				nd->next->prev = nd->prev;
				lst->count--;
			}
		}
		free (nd);
	}
}