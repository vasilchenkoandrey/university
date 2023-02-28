#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"

void initList(PDLIST lst) {
	lst->count = 0;
	lst->size = LISTSIZE;
	lst->left = lst->right = NULL;
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
				lst->right = nd; //???
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

void printList(PDLIST lst) {
	PNODE nd = lst->left;
	while(nd!=NULL) {
		printf("[%d]", nd->info);
		nd = nd->next;
	}
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
