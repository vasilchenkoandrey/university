#include <stdio.h>
#include <stdlib.h>
#include "clist.h"
#define N 10
void move(PLIST lst2, int e){
	PLNODE nd,nd1,nd2,nd3,nd4;
	int p=0;
	nd=lst2->entry;
		while(nd->next!=lst2->entry){
			if(nd->info==e){
				if(p==0){
					p=1;
					nd1=nd;
				}
				else
					nd2=nd;
			}
			nd=nd->next;
		}
		if(nd->info==e) nd2=nd;// Обрабатываем последний элемент
		//printf("%d %d",nd1->key,nd2->key);
		if(nd1->next==nd2||nd1->next->next==nd2) printf("Nothing to move\n");
		else{
			while(nd1->next->next!=nd){ // Пока последний элемент исходного списка не перемещёе к началу
				nd=nd1->next; // Перемещаем следующий элемент от начала
				nd1->next=nd1->next->next; // Исключаем его из начала
				nd1->next->prev=nd1;
				nd2->prev->next=nd; // Добавляем его перед концом
				nd->prev=nd2->prev;
				nd2->prev=nd;
				nd->next=nd2;
				nd2=nd; // Он и будет текущим концом фрагмента
			}
		}
}
int main(){
	int a[2][N]={ {1,2,3,4,5,6,7,8,9,10}, {5,9,8,6,8,5,4,8,3,1} };
	PLIST lst;
	PLNODE nd0;
	int i, e=8;
	lst = (PLIST)malloc(sizeof(list));
	init_clist(lst);
	for(i=0;i<N;i++){
		nd0=(PLNODE)malloc(sizeof(node));
		nd0->key=a[0][i];
		nd0->info=a[1][i];
		insert_in_clist(lst,nd0);
	}
	print_clist(lst);
	move(lst,e);
	print_clist(lst);
	return 0;
}
