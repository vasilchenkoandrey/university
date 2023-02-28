#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian\n");

	PLIST lst;
	PNODE nd;
	int a[] = { 1,4,2,7,12,11,9,8,10,3,5,6 };
	int i;

	/*строим*/
	printf("\nСТРОИМ\n");
	lst = (PLIST)malloc(sizeof(list));
	initList(lst);

	for (i = 0; i < 12; i++)
	{
		nd = (PNODE)malloc(sizeof(node));
		nd->key = i;
		nd->info = (a[i]);
		addBeforeHeadList(lst, nd);
	}
	printList(lst);
	printf("===========================================================================================================\n");
	/*строим*/

	/*добавляем перед head*/
	printf("\n\n\nдобавляем перед head\n");
	nd = (PNODE)malloc(sizeof(node));
	nd->key = 14;
	nd->info = 13;
	addBeforeHeadList(lst, nd);
	printList(lst);
	printf("===========================================================================================================\n");
	/*добавляем перед head*/

	/*вставляем в конец*/
	printf("\n\n\nвставляем в конец\n");
	nd = (PNODE)malloc(sizeof(node));
	nd->key = 15;
	nd->info = 15;
	insertAfterList(lst, nd, 7);
	printList(lst);
	printf("===========================================================================================================\n");
	/*вставляем в конец*/

	/*вставляем в начало*/
	printf("\n\n\nвставляем в начало\n");
	nd = (PNODE)malloc(sizeof(node));
	nd->key = 16;
	nd->info = 17;
	insertBeforeList(lst, nd, 7);
	printList(lst);
	printf("===========================================================================================================\n");
	/*вставляем в начало*/

	/*поиск 7-й ячейки*/
	printf("\n\n\nпоиск 7-й ячейки\n");
	nd = findList(lst, 7);
	if(nd != NULL)
	{
		printf("OK (%d->%d)\n", nd->key, nd->info);
	}
	printList(lst);
	printf("===========================================================================================================\n");
	/*поиск 7-й ячейки*/

	/*поиск 21-й ячейки*/
	printf("\n\n\nпоиск 21-й ячейки\n");
	findList(lst, 21);
	if(nd == NULL)
	{
		printf(" Элемент с ключом %d отсутствует", 21);
	}
	printList(lst);
	printf("===========================================================================================================\n");
	/*поиск 21-й ячейки*/

	/*удаляем ячейку 7*/
	printf("\n\n\nудаляем ячейку 7\n");
	findList(lst, 7);
	deleteList(lst, 7);
	printf("delete %d\n", 7);
	printList(lst);
	printf("===========================================================================================================\n");
	/*удаляем ячейку 7*/

	/*удаляем ячейку 22*/
	printf("\n\n\nудаляем ячейку 22\n");
	findList(lst, 22);
	deleteList(lst, 22);
	printf("delete %d\n", 22);
	printList(lst);
	printf("===========================================================================================================\n\n");
	/*удаляем ячейку 22*/


	return 0;
}