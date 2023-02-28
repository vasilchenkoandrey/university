#include <stdio.h>
#include "clist.h"

#define N 10
#define M 4

int gameCircle (PLIST lst) {

	PNODE nd, nd1;
	int i;

	nd = lst->entry;
	while (lst->count>1) { // Пока в списке не остался 1 элемент
		for (i = 1; i<M; i++) // Отсчитываем третий элемент от текущего
			nd = nd->next;
		nd1 = nd; // Сохраняем удаляемый элемент
		nd = nd->next; // Следующий становится текущим
		deleteList (lst, nd1->key); // Удаляем бывший текущий
		printList (lst);
	}

	return 0;
}

int main () {

	PNODE nd;
	int i;

	PLIST lst = (PLIST) malloc (sizeof (LIST)); // Создаём исходный список
	initList (lst);

	for (i = 0; i < N; i++) { // Заполняем исходный список
		nd = (PNODE) malloc (sizeof (NODE));
		nd->key = i + 1; // Номера присваиваются против часовой стрелки
		insertAfter (lst, nd);
	}
	printList (lst);
	gameCircle (lst);

	return 0;
}