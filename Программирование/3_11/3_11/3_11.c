#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define N 10

int main () {

	PLIST lst;
	PNODE nd, nd1, nd2, nd3, nd4;
	int i;

	lst = (PLIST) malloc (sizeof (list));
	initList (lst);

	for (i = 0; i<N; i++) { // Заполняем список
		nd = (PNODE) malloc (sizeof (node));
		nd->key = i + 1;
		nd->info = rand () % 10 + 10;
		addAfterTailList (lst, nd);
	}
	printList (lst); //Печатаем исходный список

	nd1 = lst->head; // Текущий обрабатываемый элемент
	nd2 = NULL; // Указатель на "конец списка"
	nd4 = NULL; // Указатель на предыдущий элемент
	while (nd1 != NULL) { // Пока не дошли до конца списка

		if (nd1->info % 2 == 1) { //Если число нечётное
			if (nd4 == NULL) lst->head = nd1->next; //Если он первый, сдвигаем голову
			else nd4->next = nd1->next; // Иначе перебрасываем ссылку через него (удаляем из списка)
			nd3 = nd1->next; // Запоминаем следующий за обрабатываемым
			if (nd2 == NULL) lst->tail = nd1; // Если это первое перемещение, то этот элемент будет хвостом нового списка
			nd1->next = nd2; // Прикрепляем элемент в "конец списка"
			nd2 = nd1;// Он будет новым началом "конца списка"
			nd1 = nd3; //Текущий обрабатываемый элемент - это запомненный следующий
		}

		else { // Если число чётное
			nd4 = nd1; // Текущий становится предыдущим
			nd1 = nd1->next; // Переходим к следующему
		}
	}

	if (nd4 == NULL) lst->head = nd2; // Если все перенесли в "конец списка", то его начало будет головой изменённого списка
	else nd4->next = nd2; // Иначе прикрепляем "конец списка"

	printList (lst); //Печатаем результат

	return 0;
}
