
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))

void pr(node *tmp)
{
	if (tmp == NULL)
	{
		printf("[%p]\n", tmp);
		return;
	}
	while (tmp)
	{
		printf("[%14p]<-[%14p]->[%14p] ", tmp->prev, tmp, tmp->next);
		printf("size: [%4d]\n", tmp->size);
		tmp = tmp->next;
	}
	printf("-------------\n");
}
node *add_head(node *head, int hh)
{
	node *tmp = NULL;
	if ((tmp = malloc(sizeof(node))) == NULL)
	{
		perror("malloc: NULL");
		exit(2);
	}
	tmp->prev = NULL;
	tmp->size = hh;
	if (head == NULL)
		tmp->next = NULL;
	else
	{
		tmp->next = head;
		head->prev = tmp;
	}
	return tmp;
}
node *del_head(node *head)
{
	node *tmp = head;
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	head = head->next;
	head->prev = NULL;
	free(tmp);
	return head;
}


int length(node *list)
{
	node *tmp = list;
	int res = 0;
	if (list == NULL || list->size == 0)
		return 0;
	else
	{
		while (tmp != NULL)
		{
			res++;
			tmp = tmp->next;
		}
	}
	return res;
}

void swap(node *a, node *b)
{
	node *tmp = NULL;
	if ((tmp = malloc(sizeof(node))) == NULL)
		exit(1);
	tmp->size = a->size;
	a->size = b->size;
	b->size = tmp->size;
	free(tmp);
}

node *get(node *list, int n)
{
	if (n >= length(list))
		exit(3);
	int i;
	for (i = 0; i < n; i++)
		list = list->next;
	return list;
}

node *sort(node *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	int i, j, n = length(head);
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (get(head, j)->size < get(head, i)->size)
				swap(get(head, i), get(head, j));
		}
	}
	return head;
}
pointer *add_head_address(pointer *head, node **address){
	pointer *tmp = NULL;
	if ((tmp = malloc(sizeof(pointer))) == NULL)
	{
		perror("malloc: NULL");
		exit(2);
	}
	tmp->address = address;
	if (head == NULL)
		tmp->next = NULL;
	else
	{
		tmp->next = head;
	}
	return tmp;
}

node* printextra(node *head, int len, int i){
	if (len < i || len == 0){
		for (i = 0; i < T-1; i++) printf(" ");
		printf("|");
		return head;
	}
	else{
		disk(head->size);
		printf("|");
		return head->next;
	}
} 

void prcount(char s, int n){
    int i;
    for ( i = 0; i < n; i++){
        printf("%c", s);
    }

}
void disk(int size){
	int i;
    prcount(' ',T/2-size);
    for (i = 0; i < size-1; i++){
		printf("* ");
    }
    printf("*");
    prcount(' ', T/2-size);
}
void printftof(pointer *adresses){
	node *head1 = *(adresses->address), *head2 = *(adresses->next->address), *head3 = *(adresses->next->next->address);
	int a = length(head1), b = length(head2), c = length(head3), maximum, i;
	maximum = max(max(a,b), c);
	for ( i = maximum; i > 0; i--){
		head1 = printextra(head1, a, i);
		head2 = printextra(head2, b, i);
		head3 = printextra(head3, c, i);
		printf("\n");
	}
    prcount('-', 3*T);
    printf("\n");
	printf("Tower 1");
    prcount(' ', T-8);
    printf("|Tower 2");
    prcount(' ', T-8);
    printf("|Tower 3");
    prcount(' ', T-8);
    printf("|\n");
    prcount('-', 3*T);
    printf("\n");

}

void hanoi_tower(int n, node **head_from, node **head_to, node **head_aux, pointer *adresses){	
	if (n == 0)
	{
		printf("No linked list");
		exit(6);
	}
	else if (n == 1)
	{	
		if (length(*head_to)==0) printftof(adresses);
		*head_to = add_head(*head_to, (*head_from)->size);
		*head_from = del_head(*head_from);
		if (length(*head_from)==0) printftof(adresses);
		return;
	}
	hanoi_tower(n - 1, head_from, head_aux, head_to, adresses);
    printftof(adresses);
	*head_to = add_head(*head_to, (*head_from)->size);
	*head_from = del_head(*head_from);
	printftof(adresses);
	hanoi_tower(n - 1, head_aux, head_to, head_from, adresses);
}
