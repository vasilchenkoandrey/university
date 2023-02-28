#include <stdio.h>
#include <stdlib.h>
#include "clist.h"
#define N 10
void doubl(PLIST lst2, int e){
	PLNODE nd,nd1;
	nd=lst2->entry;
		while(nd->next!=lst2->entry){
			if(nd->info==e){
				nd1=(PLNODE)malloc(sizeof(node));
				nd1->key=0;
				nd1->info=e;
				nd1->next=nd->next;
				nd->next->prev=nd1;
				nd->next=nd1;
				nd1->prev=nd;
				nd=nd1->next; // Переходим к следующему
			}
			else nd=nd->next;
		}
		if(nd->info==e){ // Проверяем последний элемент
			nd1=(PLNODE)malloc(sizeof(node));
			nd1->key=0;
			nd1->info=e;
			nd1->next=nd->next;
			nd->next->prev=nd1;
			nd->next=nd1;
			nd1->prev=nd;
		}
}
int main(){
	int a[2][N]={ {1,2,3,4,5,6,7,8,9,10}, {7,9,8,7,6,5,7,3,8,7} };
	PLIST lst;
	PLNODE nd0;
	int i;
	int e = 7;
	lst = (PLIST)malloc(sizeof(list));
	init_clist(lst);
	for(i=0;i<N;i++){
		nd0=(PLNODE)malloc(sizeof(node));
		nd0->key=a[0][i];
		nd0->info=a[1][i];
		insert_in_clist(lst,nd0);
	}
	print_clist(lst);
	doubl(lst, e);
	print_clist(lst);
	return 0;
}
