#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#define N 5
void swap_last_and_first(PSLIST lst){
	PLNODE nd1,nd2;
	nd1 = lst -> head;
	while(nd1 -> next != lst -> tail) // ����� �������������� ��������
		nd1 = nd1 -> next;
	nd2=lst->head; // ��������� ������� ������ (������ ������ �������)
	lst -> tail -> next = lst -> head->next; // ����������� ��������� ������� ������ � ���������� �� �������
	lst -> head = lst -> tail; // �������� ��������� �� ������ �� ��������� �� ������ ��������� �������
	nd1 -> next = nd2; // ����������� ������ ������ ������� � ����� ������
	lst -> tail = nd2; // ��������� �� ����� ��������� �� ������ ������ �������
	nd2 -> next = NULL; // ��� ��� ������ ������ ���� ���������, ��� ��������� �� ��������� ������������� � NULL
}
int main(){
	PSLIST lst;
	PLNODE nd;
	int i;
	lst = (PSLIST)malloc(sizeof(list));
	init_slist(lst);
	for( i=0 ; i<N ; i++ ){ // ��������� ������
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
