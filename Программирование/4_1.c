#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#define N 4
int main(){
	PLIST lst1;
	PNODE nd,nd1,nd2;
	int i,result=0; //Изначально сумма равна нулю
	lst1 = (PLIST)malloc(sizeof(list)); // Исходный список
	init_dlist(lst1);
	srand(time(0));
	for(i=1;i<=N;i++){ // Заполняем исходный список
		nd = (PNODE)malloc(sizeof(node));
		nd -> key = i;
		nd -> info  = i*i;
		put_to_right(lst1, nd);
	}
	print_dlist(lst1);
	printf("\n");
	i=1;
	nd1=lst1->left;
	nd2=lst1->right;
	while(nd1!=nd2->next){ // Пока левая и правая рука не встретились (кол-во элементов чётное)//nd1!=nd2
			result+=nd1->info*nd2->info;
			nd1=nd1->next;
			nd2=nd2->prev;
		}
	result+=result;
	printf("Result is %d\n",result);
	return 0;
}
