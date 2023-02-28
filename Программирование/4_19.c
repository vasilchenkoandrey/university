#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dlist.h"
#define DEGREE 7
int main(){
	PLIST lst;
	PNODE nd,nd1,nd2;
	int k, i;
	lst = (PLIST)malloc(sizeof(list));
	init_dlist(lst);
	srand(time(0));
	//srand(3);
	i=0;
	do{
		nd = (PNODE)malloc(sizeof(node));
		nd -> coef = rand()%(DEGREE+1)+1;
		nd -> degree = rand()%(DEGREE+1);
		put_to_right(lst, nd);
		if(i!=0) printf("+");
		i++;
		if(nd->coef>1) printf("%d",nd->coef);
		if(nd->degree!=0){
			if(nd->degree==1) printf("X");
			else printf("X^%d",nd->degree);
		}
		else if(nd->coef==1) printf("1");
	} while(nd->degree!=DEGREE);
	//printf("\n");
	//print_dlist(lst);
	printf("\n");
	for(i = DEGREE; i>=0; i--){ // Перебор всех возможных степеней
		nd = lst -> left; // Устанавливаем левый указатель
		while(nd!=NULL && nd -> degree!=i) nd = nd -> next; // Пока не конец списка и степень не равна
		// текущей перебираемой
		if(nd!=NULL){ // Если нашли
			nd1 = lst -> right;// Устанавливаем правый указатель
			while(nd1!=nd){ // Пока правый и левый указатели не будут равны
				if(nd -> degree == nd1 -> degree){ // Если степени равны
					nd -> coef +=nd1 -> coef;// то увеличиваем коэффициент левого указателя на величину коэффициента правого
					nd1->prev->next = nd1 -> next;
					nd1 -> next -> prev = nd1 -> prev;
					nd2 = nd1;
					nd1 = nd1 -> prev;
					free(nd2);
				}
				else nd1 = nd1 -> prev;
			}
			if(nd->prev==NULL) lst->left=nd->next;
			else nd->prev->next=nd->next;
			if(nd->next==NULL) lst->right=nd->prev;
			else nd->next->prev=nd->prev;
			lst->count--;
			put_to_right(lst,nd);
		}
	}
	print_dlist(lst);
	printf("\n");
	nd=lst->left;
	k=0;
	while(nd!=NULL){
		if(k!=0) printf("+");
		k++;
		if(nd->coef>1) printf("%d",nd->coef);
		if(nd->degree!=0){
			if(nd->degree==1) printf("X");
			else printf("X^%d",nd->degree);
		}
		else if(nd->coef==1) printf("1");
		nd=nd->next;
	}
}
