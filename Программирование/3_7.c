#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#define N 5
int main(){
	PSLIST lst;
	PLNODE nd, nd1, nd2, nd3, nd4;
	int i;
	lst = (PSLIST)malloc(sizeof(list));
	init_slist(lst);
	for( i=0 ; i<N ; i++ ){
		nd=(PLNODE)malloc(sizeof(node));
		nd -> key = (i+1);
		nd -> info = rand()%10;
		append_to_slist(lst,nd);//// 1
	}
	print_slist(lst);//Печатаем исходный список
	nd1=lst->head; // Текущий обрабатываемый элемент
	nd2=NULL; // Указатель на "конец списка"
	nd4=lst->tail; // Указатель на последний элемент изначального списка
	while(nd1!=nd4){ // Пока не дошли до последнего элемента
		nd3=nd1->next; // Запоминаем следующий за обрабатываемым
		if(nd2==NULL) lst->tail=nd1; // Если это первое перемещение, то этот элемент будет хвостом нового списка
		nd1->next=nd2; // Прикрепляем элемент в "конец списка"
		nd2=nd1;// Он будет новым началом "конца списка"
		nd1=nd3; //Текущий обрабатываемый элемент - это запомненный следующий
	}
	lst->head=nd1; // Последний элемент старого списка становится головой нового
	nd1->next=nd2; // К нему прикрепляем сформированный "конец списка"
	print_slist(lst); //Печатаем результат
	return 0;
}
