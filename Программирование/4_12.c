#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dlist.h"
#define N 28
int main(){
	PLIST lst;
	PNODE nd, ndj,ndk;
	int i,k,j,l;
	int a[]={1,1,2,2,2,3,3,3,5};
	lst = (PLIST)malloc(sizeof(list));
	init_dlist(lst);
	/*l=0;
	for(i=0;i<3;i++){
		nd = (PNODE)malloc(sizeof(node));
		nd -> key  = a[l]; l++;
		nd -> first = a[l]; l++;
		nd -> second  = a[l]; l++;
		put_to_right(lst, nd);
	}*/
	//srand(time(0));
	srand(3);
	l=1;
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
	//print_dlist(lst);
	//printf("\n");
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
		if(ndk->prev==NULL)
			lst->left=ndk->next;
		else ndk->prev->next=ndk->next;
		if(ndk->next==NULL)
			lst->right=ndk->prev;
		else ndk->next->prev=ndk->prev;
		lst->count--;
		insert_after(lst,ndk,ndj->key);
	}
	//print_dlist(lst);
	//printf("\n");
	nd=lst->left;
	i=24;
	while(nd!=NULL && i!=0){
		i--;
		ndj=nd->next;
		delete_from_dlist(lst,nd->key);
		nd=ndj;
	}
	i=1;
	if(lst->count>1){
		nd=lst->left;
		ndj=NULL;
		while(nd!=NULL && i!=0){
			if(ndj!=NULL){
				if(ndj->second!=nd->first)
					i=0;
			}
			ndj=nd;
			nd=nd->next;
		}
	}
	if(i==1)
		printf("Right\n");
	else
		printf("Wrong\n");
	print_dlist(lst);
	printf("\n");
}
