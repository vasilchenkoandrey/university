#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"
#include <locale.h>

void initList(PDLIST lst) {
	lst->count = 0;
	lst->size = LISTSIZE;
	lst->left = lst->right = NULL;
}

PDLIST buildList (int n) {

	PDLIST lst;
	PNODE nd;
	int i, keyCounter = 0;

	lst = (PDLIST) malloc (sizeof (DLIST));
	initList (lst);

	for (i = 0; i < n; i++) {
		nd = (PNODE) malloc (sizeof (NODE));
		nd->key = keyCounter;
		nd->info = 1 + rand () % 5;
		addLeft (lst, nd);
		keyCounter++;
	}
	return lst;
}

bool isEmpty(PDLIST lst) {
	return lst->count==0?true:false;
}

bool isOverflow(PDLIST lst) {
	return lst->count>=lst->size?true:false;
}

bool addLeft(PDLIST lst, PNODE nd) {
	bool res = false;
	if(!isOverflow(lst)) {
		res = true;
		if(isEmpty(lst)) {
			lst->count=1;
			lst->left = lst->right = nd;
			nd->prev = nd->next = NULL;
		} else {
			lst->count++;
			nd->next = lst->left;
			nd->prev = NULL;
			lst->left->prev = nd;
			lst->left = nd;
		}
	}
	return res;
}

bool addRight(PDLIST lst, PNODE nd) {
	bool res = false;
	if(!isOverflow(lst)) {
		res = true;
		if(isEmpty(lst)) {
			lst->count=1;
			lst->left = lst->right = nd;
			nd->prev = nd->next = NULL;
		} else {
			lst->count++;
			lst->right->next = nd;
			nd->prev = lst->right;
			nd->next = NULL;
			lst->right = nd;
		}
	}
	return res;
}

PNODE getLeft(PDLIST lst) {
	PNODE nd = NULL;
	if(!isEmpty(lst)) {
		if(lst->count==1) {
			nd = lst->left;
			lst->count = 0;
			lst->left = lst->right = NULL;
		} else {
			nd = lst->left;
			lst->count--;
			lst->left = lst->left->next;
			lst->left->prev = NULL;
		}
	}
	return nd;
}

PNODE getRight(PDLIST lst) {
	PNODE nd = NULL;
	if(!isEmpty(lst)) {
		if(lst->count==1) {
			nd = lst->right;
			lst->count = 0;
			lst->left = lst->right = NULL;
		} else {
			nd = lst->right;
			lst->count--;
			lst->right = lst->right->prev;
			lst->right->next = NULL;
		}
	}
	return nd;
}

PNODE findList(PDLIST lst, int k) {
	PNODE nd = lst->left;
	while(nd!=NULL && nd->key!=k) {
		nd = nd->next;
	}
	return nd;
}

bool deleteList(PDLIST lst, int k) {
	bool res = false;
	PNODE nd = findList(lst, k);
	if(nd!=NULL) {
		res = true;
		nd->prev->next = nd->next;
		nd->next->prev = nd->prev;
		lst->count--;
		free(nd);
	}
	return res;
}

bool insertLeft(PDLIST lst, PNODE nd, int k) {
	PNODE nd1;
	bool res = false;
	if(!isOverflow(lst)) {
		res = true;
		if(isEmpty(lst)) {
			lst->count = 1;
			lst->right = lst->left = nd;
			nd->prev = nd->next = NULL;
		} else {
			nd1 = findList(lst, k);
			if(nd1==NULL || nd1==lst->right) {
				nd->prev = lst->right;
				lst->right->next = nd;
				nd->next = NULL;
				lst->right = nd;
				lst->count++;
			} else {
				nd->next = nd1->next;
				nd1->next->prev = nd;
				nd1->next = nd;
				nd->prev = nd1;
				lst->count++;
			}
		}
	}
	return res;
}

bool insertRight(PDLIST lst, PNODE nd, int k) {
	PNODE nd1;
	bool res = false;
	if(!isOverflow(lst)) {
		res = true;
		if(isEmpty(lst)) {
			lst->count = 1;
			lst->right = lst->left = nd;
			nd->prev = nd->next = NULL;
		} else {
			nd1 = findList(lst, k);
			if(nd1==NULL || nd1==lst->left) {
				nd->next = lst->left;
				lst->left->prev = nd;
				nd->prev = NULL;
				lst->left = nd;
				lst->count++;
			} else {
				nd->prev = nd1->prev;
				nd->next = nd1;
				nd1->prev->next = nd;
				nd1->prev = nd;
				lst->count++;
			}
		}
	}
	return res;
}

void printList(PDLIST lst, int n) {
	PNODE nd = lst->left;
	int i;
	printf ("LIST:\n");
	for (i = 0; i < n; i++)
		printf("====");
	printf("\n");
	while(nd!=NULL) {
		printf("[%d] ", nd->info);
		nd = nd->next;
	}
	printf("\n");
	for (i = 0; i < n; i++)
		printf("====");
	printf("\n");
}

int iteration (PDLIST lst, int n) {

	PNODE nd, nd1;
	int res, i;

	nd = lst->left;
	nd1 = lst->right;
	res = 1;
	for (i = 0; i < n; i++)
		printf ("-------");
	endl;
	while ((nd != NULL) || (nd1 != NULL)) {
		if (nd != lst->right)
			printf ("(%d+%d)*", nd->info, nd1->info);
		else
			printf ("(%d+%d)", nd->info, nd1->info);
		res = res * (nd->info + nd1->info);
		nd = nd->next;
		nd1 = nd1->prev;
	}
	printf ("=%d", res);
	endl;
	for (i = 0; i < n; i++)
		printf ("-------");
	endl;
	return 0;
}

void destroy(PDLIST lst) {
	PNODE nd, nd1;
	nd = nd1 = lst->left;
	while(nd!=NULL) {
		nd1 = nd;
		nd = nd->next;
		free(nd1);
	}
}
