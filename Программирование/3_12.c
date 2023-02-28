#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#define N 10
void replace(PSLIST lst,int e1,int e2){ // ������� �������� ��� ��������� �������� e1 �� e2
	PLNODE nd1;
	nd1 = lst -> head;
	while(nd1!=NULL){ // ���� �� ����� ������
		if(nd1->info==e1) // ���� ��������� �������� e1
			nd1->info=e2;// �������� ��� �� e2
		nd1 = nd1 -> next;
	}
}
int main(){
	PSLIST lst;
	PLNODE nd, e1, e2;
	int i;
	lst = (PSLIST)malloc(sizeof(list));
	init_slist(lst);
	for( i=0 ; i<N ; i++ ){ // ��������� ������
		nd=(PLNODE)malloc(sizeof(node));
		nd -> key = (i+1);
		nd -> info = rand()%10;
		append_to_slist(lst,nd);
	}
	print_slist(lst);
	e1=(PLNODE)malloc(sizeof(node)); // ���������� �������
	e2=(PLNODE)malloc(sizeof(node)); // ���������� �������
	printf("Please enter e1 and e2\n");
	scanf("%d %d",&e1->info,&e2->info);
	replace(lst,e1->info,e2->info);
	print_slist(lst);
	return 0;
}
