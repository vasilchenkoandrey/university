#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#define N 10
void replace(PSLIST lst,int e1,int e2){ // Функция заменяет все вхождения элемента e1 на e2
	PLNODE nd1;
	nd1 = lst -> head;
	while(nd1!=NULL){ // Цикл до конца списка
		if(nd1->info==e1) // Если встретили значение e1
			nd1->info=e2;// Заменяем его на e2
		nd1 = nd1 -> next;
	}
}
int main(){
	PSLIST lst;
	PLNODE nd, e1, e2;
	int i;
	lst = (PSLIST)malloc(sizeof(list));
	init_slist(lst);
	for( i=0 ; i<N ; i++ ){ // Заполняем список
		nd=(PLNODE)malloc(sizeof(node));
		nd -> key = (i+1);
		nd -> info = rand()%10;
		append_to_slist(lst,nd);
	}
	print_slist(lst);
	e1=(PLNODE)malloc(sizeof(node)); // Заменяемый элемент
	e2=(PLNODE)malloc(sizeof(node)); // Заменяющий элемент
	printf("Please enter e1 and e2\n");
	scanf("%d %d",&e1->info,&e2->info);
	replace(lst,e1->info,e2->info);
	print_slist(lst);
	return 0;
}
