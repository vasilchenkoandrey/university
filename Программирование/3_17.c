#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include "slist.h"
#define N 5
void search_identical_el(PSLIST lst){
	PLNODE nd1, nd2;
	int p;
	nd1=lst->head; //Начинаем левой рукой с головы
	p=0; //Признак наличия одинаковых элементов
	while(nd1!=NULL) { //Пока не дошли левой рукой до конца
		nd2=nd1->next; //Начинаем правой рукой со следующего за левой рукой
		while (nd2!=NULL) { //Пока не дошли правой рукой до конца
			if (nd2->info==nd1->info) { // Если нашли одинаковые элементы
				p=1; // Устанавливаем признак в еденицу
				break; // Прекращаем проверку
			}
			else // Если элементы не совпадают
				nd2=nd2->next; //Перемещаем текущий к следующему
		}
		if (p==1) { // Если были найдены одинаковые элементы
			printf("The list includes at least two identical elements\n");
			break; // Прекращаем поиск
			}
		nd1=nd1->next;
	}
	if (p==0) printf("The list does not include identical elements\n"); // Если не нашли одинаковые
}
int main(){
	PSLIST lst;
	PLNODE nd;
	int i;
	lst = (PSLIST)malloc(sizeof(list));
	init_slist(lst);
	//srand(time(0));
	for( i=0 ; i<N ; i++ ){
		nd=(PLNODE)malloc(sizeof(node));
		nd -> key = (i+1);
		nd -> info = rand()%100;
		append_to_slist(lst,nd);
	}
	print_slist(lst);//Печатаем исходный список
	search_identical_el(lst); // Проверка на наличие одинаковых элементов
	return 0;
}
