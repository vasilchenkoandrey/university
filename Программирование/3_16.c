#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#define N 10
void entry(PSLIST L1, PSLIST L2){
	PLNODE nd1,nd2,nd3;
	nd1=L1->head;
	while(nd1!=NULL){ // Идём до конца списка L1
		nd2=find_in_slist2(L2,nd1->info); // Ищем элементы списка L1 в списке L2
		if(nd2==NULL){ // Если не нашли
			printf("List L1 is not included in list L2\n"); // Список L1 не содержится в списке L2
			break; // Прекращаем поиск
		}
		nd1=nd1->next; // Переходим к следующему
	}
	if(nd1==NULL) // Если прошли до конца списка, то это значит, что нашли каждый элемент списка L1 в списке L2
		printf("List L1 is included in list L2\n"); // Следовательно, список L1 входит в список L2
}

int main(){
	PSLIST L1,L2;
	PLNODE nd1;
	int i;
	int l1[]={7,8,3,7,9,8,5,8,6,4};
	int l2[]={1,7,8,3,5,9,6,4,0,0};
	L1 = (PSLIST)malloc(sizeof(list));
	init_slist(L1);
	for( i=0 ; i<N; i++ ){
		nd1=(PLNODE)malloc(sizeof(node));
		nd1->key=(i+1);
		nd1->info=l1[i];
		append_to_slist(L1,nd1);
	}
	printf("List L1:\n");
	print_slist(L1);
	printf("\n");
	L2 = (PSLIST)malloc(sizeof(list));
		init_slist(L2);
		for( i=0 ; i<N ; i++ ){
			nd1=(PLNODE)malloc(sizeof(node));
			nd1->key=(i+1);
			nd1->info=l2[i];
			append_to_slist(L2,nd1);
		}
	printf("List L2:\n");
	print_slist(L2);
	printf("\n");
	entry(L1,L2);
	return 0;
}
