#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#define N 5
int main(){
	PSLIST A,B,C;
	PLNODE nd1,nd2,nd3,nd4;
	int i;
	A = (PSLIST)malloc(sizeof(list));
	init_slist(A);
	for( i=0 ; i<N ; i++ ){ // Заполняем список
		nd1=(PLNODE)malloc(sizeof(node));
		nd1->key=(i+1);
		nd1->info=i*i;
		append_to_slist(A,nd1);
	}
	printf("List A:\n");
	print_slist(A);
	printf("\n");
	B = (PSLIST)malloc(sizeof(list));
		init_slist(B);
		for( i=0 ; i<N ; i++ ){ // Заполняем список
			nd1=(PLNODE)malloc(sizeof(node));
			nd1->key=(i+1);
			nd1->info=i*i-5;
			append_to_slist(B,nd1);
		}
	printf("List B:\n");
	print_slist(B);
	printf("\n");
	C = (PSLIST)malloc(sizeof(list));// Список из элементов списка B, которых нет в A
	init_slist(C);
	nd2=B->head;
	while(nd2!=NULL){ // Заполняем список из элементов списка B, которых нет в A
		nd4=nd2->next;
		nd3=find_in_slist2(A,nd2->info); //*
		if(nd3==NULL){ // Если не нашли
			nd1=(PLNODE)malloc(sizeof(node));
			nd1->key=nd2->key;
			nd1->info=nd2->info;
			append_to_slist(C,nd1);
		}
		nd2=nd4; // Переходим к следующему
	}
	printf("List C:\n");
	print_slist(C);
	nd1=A->tail;
	nd2=nd3=A->head;
	while(nd2!=nd1->next){ // Удаляем из списка А элементы, имеющиеся в списке В
		nd4=find_in_slist2(B,nd2->info);//
		if(nd4!=NULL){ // Если нашли
			if(nd2==A->head){ // Если нужно удалить голову
				A->head=A->head->next; // Делаем головой следующий за головой
				nd2=nd3=A->head; // Начинаем с головы
			}
			else{ // Если удаляемый элемент не является головой
				nd3->next=nd2->next; // Перебрасываем ссылку через удаляемый элемент
				nd3=nd2; // Текущий становится предыдущим
				nd2=nd2->next; // Переходим к следующему
			}
		}
		else{ // Если не нашли
			nd3=nd2; // Текущий становится предыдущим
			nd2=nd2->next; // Переходим к следующему
		}
	}
	A->tail->next=C->head; // Прикрепляем в конец списка А элементы списка В, которых нет в А
	printf("Modified list A:\n");
	print_slist(A);
	return 0;
}
