#include <stdio.h>
#include <stdlib.h>
///#include <time.h>
#include "dlist.h"
#define N 28
int main(){
	PLIST lst;
	PNODE nd, ndj,ndk;
	int i,k,j,l;
	lst = (PLIST)malloc(sizeof(list));
	init_dlist(lst);
	//srand(time(0));
	l=1;
	srand(3);
	for(i=0;i<7;i++) //Перебираем масти
		for(k=0;k<7;k++){ // Перебираем значения
			if(find_in_dlist2(lst,i,k)==NULL){
				nd = (PNODE)malloc(sizeof(node));
				nd -> first = i;
				nd -> second  = k;
				nd -> key  = l;
				l++;
				put_to_right(lst, nd);
			}
		}
	print_dlist(lst);
	printf("\n");
	for (i=0;i<N*4;i++) { // Цикл перемешивания в два раза больше чем количество карт
		do { // Получаем два случайных числа
			k=rand()%N;
			j=rand()%N;
		} while (k==j); // Числа должны быть не равны
		nd=lst->left;
		l=0;
		while(nd!=NULL){
			if(l==k)
				ndk=nd;
			if(l==j)
				ndj=nd;
			nd=nd->next;
			l++;
		}
		//printf("k=%d j=%d ndk=%d ndj=%d ",k,j,ndk->key,ndj->key);
		if(ndk->prev==NULL)
			lst->left=ndk->next;
		else ndk->prev->next=ndk->next;
		if(ndk->next==NULL)
			lst->right=ndk->prev;
		else ndk->next->prev=ndk->prev;
		lst->count--;
		insert_after(lst,ndk,ndj->key);
		//print_dlist(lst);
		//printf("\n");
	}
	printf("\n");
	print_dlist(lst);
	printf("\n");
	while(delete_from_dlist2(lst));
	print_dlist(lst);
}
