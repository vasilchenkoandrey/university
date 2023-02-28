#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#define N 5
void swap_last_and_first(PSLIST lst){
	PLNODE nd1,nd2;
	nd1 = lst -> head;
	while(nd1 -> next != lst -> tail) // Поиск предпоследнего элемента
		nd1 = nd1 -> next;
	nd2=lst->head; // Сохраняем прошлую голову (бывший первый элемент)
	lst -> tail -> next = lst -> head->next; // Привязываем последний элемент списка к следующему за головой
	lst -> head = lst -> tail; // Изменяем указатель на голову на указатель на бывший последний элемент
	nd1 -> next = nd2; // Привязываем бывший первый элемент к концу списка
	lst -> tail = nd2; // Указатель на хвост указывает на бывший первый элемент
	nd2 -> next = NULL; // Так как бывший первый стал последним, его указатель на следующий устанавливаем в NULL
}
int main(){
	PSLIST lst;
	PLNODE nd;
	int i;
	lst = (PSLIST)malloc(sizeof(list));
	init_slist(lst);
	for( i=0 ; i<N ; i++ ){ // Заполняем список
		nd=(PLNODE)malloc(sizeof(node));
		nd -> key = (i+1);
		nd -> info = i*i;
		append_to_slist(lst,nd);
	}
	print_slist(lst);
	swap_last_and_first(lst);
	print_slist(lst);
	return 0;
}
