
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
		printf("data: [%4ld] s[%s]\n", tmp->data, tmp->s);
		tmp = tmp->next;
	}
	printf("-------------\n");
}
node *add_head(node *head, int hh)
{
	node *tmp = NULL;
	int i;
	if ((tmp = malloc(sizeof(node))) == NULL)
	{
		perror("malloc: NULL");
		exit(2);
	}
	tmp->prev = NULL;
	tmp->data = hh;
	for (i = 0; i < N - 1; i++)
		tmp->s[i] = ((char)(65 + rand() % 25));
	tmp->s[N - 1] = '\0';
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
	if (list == NULL)
		return 0;
	if (list->data == 0 && !strcmp(list->s, "\0"))
		return 0;
	else
	{
		while (tmp->prev != NULL)
			tmp = tmp->prev;
		while (tmp != NULL)
		{
			res++;
			tmp = tmp->next;
		}
	}
	return res;
}

node *adv_add_head(node *head, int hh, char string[])
{
	node *tmp = NULL;
	if ((tmp = malloc(sizeof(node))) == NULL)
	{
		perror("malloc: NULL");
		exit(2);
	}
	tmp->prev = NULL;
	tmp->data = hh;
	memcpy(tmp->s, string, N);
	if (head == NULL)
		tmp->next = NULL;
	else
	{
		tmp->next = head;
		head->prev = tmp;
	}
	return tmp;
}
void swap(node *a, node *b)
{
	node *tmp = NULL;
	if ((tmp = malloc(sizeof(node))) == NULL)
		exit(1);
	tmp->data = a->data;
	a->data = b->data;
	b->data = tmp->data;
	memcpy(tmp->s, a->s, N);
	memcpy(a->s, b->s, N);
	memcpy(b->s, tmp->s, N);
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
			if (get(head, j)->data < get(head, i)->data)
				swap(get(head, i), get(head, j));
		}
	}
	return head;
}
node* printextra(node *head, int len, int i){
	if (len < i || len == 0){
		printf("******************************************|");
		return head;
	}
	else{
		printf("[%14p] data: [%4ld] s[%s]|", head, head->data, head->s);
		return head->prev;
	}
} 
node *end(node *head){
	node *tmp = NULL;
	tmp = head;
	if (head == NULL) return head;
 	while (tmp->next != NULL) tmp = tmp->next;
	return tmp;
}

void printftof(node *head1, node *head2, node *head3){
	int a = length(head1), b = length(head2), c = length(head3), maximum, i;
	maximum = max(a,b);
	maximum = max(maximum, c);
	head1 = end(head1);
	head2 = end(head2);
	head3 = end(head3);
	for ( i = maximum; i > 0; i--){
		head1 = printextra(head1, a, i);
		head2 = printextra(head2, b, i);
		head3 = printextra(head3, c, i);
		printf("\n");
	}
	printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Tower 1                                   |Tower 2                                   |Tower 3                                   |\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------\n\n");
}
int max(int a, int b){
	if (a < b) return b;
	else return a;
}

void hanoi_tower(int n, node **head_from, node **head_to, node **head_aux, node **const tower1, node **const tower2, node **const tower3){	
	if (n == 0)
	{
		printf("No linked list");
		exit(6);
	}
	else if (n == 1)
	{	
		if (length(*head_to)==0) printftof(*tower1, *tower2, *tower3);
		*head_to = adv_add_head(*head_to, (*head_from)->data, (*head_from)->s);
		*head_from = del_head(*head_from);
		if (length(*head_from)==0) printftof(*tower1, *tower2, *tower3);
		return;
	}
	hanoi_tower(n - 1, head_from, head_aux, head_to, tower1, tower2, tower3);
	printftof(*tower1, *tower2, *tower3);
	*head_to = adv_add_head(*head_to, (*head_from)->data, (*head_from)->s);
	*head_from = del_head(*head_from);
	printftof(*tower1, *tower2, *tower3);
	hanoi_tower(n - 1, head_aux, head_to, head_from, tower1, tower2, tower3);
}
