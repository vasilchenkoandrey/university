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
		printf ("[%d] -> ", nd->key);
		nd = nd->next;
		while (nd->next != lst->entry->next) {
			printf ("[%d] -> ", nd->key);
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

PNODE findList (PLIST lst, int k) {
	PNODE nd = NULL;
	if (!isEmpty (lst)) {
		nd = lst->entry;
		while ((nd->next != lst->entry) && nd->key != k) {
			nd = nd->next;
		}
	}
	return nd;
}

void deleteList (PLIST lst, int k) {
	PNODE nd;
	nd = findList (lst, k);
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