#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initList(PLIST lst) {
	lst->count = 0;
	lst->size = LISTSIZE;
	lst->head = lst->tail = NULL;
}
bool emptyList(PLIST lst) {
	return(lst->count == 0) ? true : false;
}
bool overflowList(PLIST lst) {
	return(lst->count == lst->size) ? true : false;
}
bool addBeforeHeadList(PLIST lst, PNODE nd) {
	bool res = true;
	if (overflowList(lst))
		res = false;
	else {
		if (emptyList(lst)) {
			lst->count = 1;
			lst->head = lst->tail = nd;
			nd->next = NULL;
		}
		else {
			lst->count++;
			nd->next = lst->head;
			lst->head = nd;
		}

	}
	return res;
}
bool addAfterTailList(PLIST lst, PNODE nd) {
	bool res = true;
	if (overflowList(lst))
		res = false;
	else {
		if (emptyList(lst)) {
			lst->count = 1;
			lst->head = lst->tail = nd;
			nd->next = NULL;
		}
		else {
			lst->tail->next = nd;
			lst->tail = nd;
			nd->next = NULL;
			lst->count++;
		}
	}
	return res;
}
PNODE getFromHeadList(PLIST lst) {
	PNODE nd = NULL;
	if (!emptyList(lst)) {
		if (lst->count == 1) {
			nd = lst->head;
			initList(lst);
		}
		else if (lst->count > 2) {
			nd = lst->head;
			lst->count--;
			lst->head = lst->head->next;

		}
		else {
			nd = lst->head;
			lst->head = lst->tail;
			lst->count = 1;
		}

	}
	return nd;
}
PNODE getFromTailList(PLIST lst) {
	PNODE nd = NULL;
	if (!emptyList(lst))
	{
		if (lst->count == 1)
		{
			nd = lst->head;
			initList(lst);
		}
		else if (lst->count == 2) {
			nd = lst->tail;
			lst->tail = lst->head;
			lst->count = 1;
		}
		else {
			PNODE nd1;
			nd1 = lst->head;
			while (nd1->next != lst->tail)
				nd1 = nd1->next;
			nd = lst->tail;
			lst->tail = nd1;
			nd1->next = NULL;
			lst->count--;
		}
	}
	return nd;
}
void insertAfterList(PLIST lst, PNODE nd, int k) {
	PNODE nd1;
	if (!overflowList(lst)) {
		if (!emptyList(lst)) {
			nd1 = lst->head;
			while ((nd1 != NULL) && (nd1->key != k))
				nd1 = nd1->next;
			if (nd1 == NULL) {
				lst->tail->next = nd;
				lst->tail = nd;
				lst->count++;
			}
			else if (nd1 != lst->tail) {
				nd->next = nd1->next;
				nd1->next = nd;
				lst->count++;
			}
			else {
				lst->tail->next = nd;
				lst->tail = nd;
				nd->next = NULL;
				lst->count++;
			}
		}
		else {
			lst->head = lst->tail = nd;
			nd->next = NULL;
			lst->count = 1;
		}
	}
}
void insertBeforeList(PLIST lst, PNODE nd, int k) {
	PNODE cr, pr;
	if (!overflowList(lst)) {
		if (emptyList(lst)) {
			lst->count = 1;
			lst->head = lst->tail = nd;
			nd->next = NULL;
		}
		else if (lst->count == 1) {
			if (lst->head->key == k) {
				nd->next = lst->head;
				lst->head = nd;
				lst->count++;
			}
			else {
				lst->tail->next = nd;
				lst->tail = nd;
				nd->next = NULL;
				lst->count++;
			}
		}
		else {
			cr = pr = lst->head;
			while (cr != NULL && cr->key != k) {
				pr = cr;
				cr = cr->next;
			}
			if (cr == NULL) {
				lst->tail = nd;
				nd->next = NULL;
				lst->tail = nd;
				lst->count++;
			}
			else {
				nd->next = pr->next;
				pr->next = nd;
				lst->count++;
				if (pr == lst->head)
					lst->head = nd;
			}
		}
	}
}
PNODE findList(PLIST lst, int k) {
	PNODE nd;
	nd = lst->head;
	while (nd != NULL && nd->key != k)
		nd = nd->next;
	return nd;
}
void deleteList(PLIST lst, int k) {
	PNODE nd = lst->head;
	PNODE pr = nd;
	while (nd != NULL && nd->key != k) {
		pr = nd;
		nd = nd->next;
	}
	if (nd != NULL) {
		if (lst->count == 1) {
			lst->head = lst->tail = NULL;
			lst->count = 0;
			free(nd);
		}
		else {
			if (nd == lst->head) {
				lst->head = nd->next;
				lst->count--;
				free(nd);
			}
			else if (nd == lst->tail) {
				pr->next = NULL;
				lst->tail = pr;
				lst->count--;
				free(nd);
			}
			else {
				pr->next = nd->next;
				lst->count--;
				free(nd);
			}
		}
	}
}
void printList(PLIST lst) {
	PNODE nd = lst->head;
	while (nd != NULL) {
		printf("%d) %d \n", nd->key, nd->info);
		nd = nd->next;
	}
	printf("\n\n");
}
void destroy(PLIST lst) {
	PNODE nd, nd1;
	nd = lst->head;
	while (nd != NULL) {
		nd1 = nd;
		nd = nd->next;
		free(nd1);
	}
	initList(lst);
}
