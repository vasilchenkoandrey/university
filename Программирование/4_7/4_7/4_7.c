#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#define N 36

int main () {
	int i, j;
	PDLIST lst;
	PNODE nd;
	char *s;//Объявляем только указатель
	char *s1;//Тоже
	char s2 [50];//А для поиска не обязательно - одноразовое использование
	lst = (PDLIST) malloc (sizeof (list));
	initList (lst);
	do {
		printf ("\n1 - Add book\n2 - Print catalog\n3 - Delete book\n4 - Find by name\n0 - Exit\nMake your choice:");
		scanf ("%d", &i);
		if (i == 1) {
			s = (char*) malloc (50);//Под каждую книгу выделяем память, потому что в список идут только указатели
			printf ("Enter isbn:");
			scanf ("%s", s);//С пробелами вводить нельзя
			s1 = (char*) malloc (50);
			printf ("Enter title:");
			scanf ("%s", s1);
			printf ("added as %d\n", add_to_lib (lst, s, s1));
		}
		if (i == 2)
			print_dlist (lst);
		if (i == 3) {
			printf ("Enter card number:");
			scanf ("%d", &j);
			delete_from_dlist (lst, j);
		}
		if (i == 4) {
			printf ("Enter name:");
			scanf ("%s", s2);//Переменная для поиска может быть массивом - она каждый раз новая и никуда не записывается
			nd = find_in_dlist_by_name (lst, s2);
			if (nd == NULL) printf ("Not found\n");
			else printf ("Found as %s\n", nd->title);
			printf ("Entities: %i\n", print_by_name (lst, s2));
		}
	}
	while (i != 0);
	//nd=find_in_dlist_by_isbn(lst,"IEE-5689/22");
	//if(nd==NULL) printf("Not found\n");
	//else printf("Found as %d\n", nd->id);
	//
	//print_dlist(lst);
}
