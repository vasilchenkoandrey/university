#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dlist.h"
#define N 5
int main(){
	PLIST lst;
	PNODE nd,nd1,nd2;
	char a[N]={'A','B','C','D','E'};
	int b[N]={11,5,7,8,0};
	int i, distance=0; // ���������� ���������� ����� ����
	char s1,s2;
	lst = (PLIST)malloc(sizeof(list)); // �������� ������
	init_dlist(lst);
	srand(time(0));
	//srand(3);
	for(i=0;i<N;i++){ // ��������� �������� ������
		nd = (PNODE)malloc(sizeof(node));
		nd -> name  = a[i];
		nd -> key = b[i];
		put_to_right(lst, nd);
	}
	print_dlist(lst);
	printf("\n");

	printf("Please enter two stations\n");
	scanf("%c %c",&s1,&s2);
	nd1=lst->left;
	while(nd1->name!=s1 && nd1->name!=s2) // ���� ���� �� ���������, ��������� � ������ ������
		nd1=nd1->next;
	nd2=lst->right;
	while(nd2->name!=s1 && nd2->name!=s2) // ���� ���� �� ���������, ��������� � ������ ������
		nd2=nd2->prev;
	while(nd1!=nd2){ // ���� �� ����� �� ����� ��������� � ������, ��������� ����������
		distance+=nd1->key;
		nd1=nd1->next;
	}
	printf("Distance between %c and %c is %d",s1,s2,distance);
	return 0;
}
