#include "lib.h"


void linked_print(LinkedList* l) {    
    while (l != NULL) {
        printf("%d %s\n", l->x, l->name);
        l = l->next;
    }
}

LinkedList* add_tail(LinkedList* l, LinkedList node) {
    if (l->x == 0 && !strcmp(l->name, "\0")) {
        l->x = node.x;
        memcpy(l->name, node.name, STR_LEN);
        l->next = NULL;
        l->prev = NULL;
        return l;
    }

    LinkedList* res = l;
    while (l->next != NULL) l = l->next;

    LinkedList* tmp = malloc(sizeof(LinkedList));
    tmp->x = node.x;
    memcpy(tmp->name, node.name, STR_LEN);
    tmp->prev = l;
    l->next = tmp;
    return res;
}

LinkedList* add_head(LinkedList* l, LinkedList node) {
    if (l->x == 0 && !strcmp(l->name, "\0")) {
        l->x = node.x;
        memcpy(l->name, node.name, STR_LEN);
        l->next = NULL;
        l->prev = NULL;
        return l;
    }

    LinkedList* tmp = malloc(sizeof(LinkedList));
    if (tmp == NULL)
        exit(1);
    
    tmp->next = l;
    l->prev = tmp;
    tmp->prev = NULL;
    tmp->x = node.x;
    memcpy(tmp->name, node.name, STR_LEN);
    return tmp;
}

LinkedList* del_head(LinkedList* l) {
    if (l == NULL) return NULL;
    if (l->next == NULL) {
        free(l);
        return NULL;
    }
    LinkedList* tmp = l->next;
    tmp->prev = NULL;
    free(l);
    return tmp;
}

void del_tail(LinkedList* l) {
    if (l == NULL) return;
    else if (l->next == NULL) {
        free(l);
        l = NULL;
        return;
    }
    while (l->next != NULL) l = l->next;
    LinkedList* tmp = l->prev;
    l->prev = NULL;
    free(l);
    tmp->next = NULL;
}

int len(LinkedList* l) {
    int res = 0;
    if (l->x == 0 && !strcmp(l->name, "\0"))
        return 0;
    
    while (l != NULL) {
        res++;
        l = l->next;
    }
    return res;
}

LinkedList get(LinkedList* l, int n) {
    if (n > len(l)) exit(3);
    int i;
    for (i = 0; i < n; i++) {
        l = l->next;
    }
    return *l;
}

void tower_of_hanoi(int n, LinkedList* start, LinkedList* finish, LinkedList* tmp) {
    if (n == 1) {
        finish = add_head(finish, get(start, 0));
        start = del_head(start);
        return;
    }

    tower_of_hanoi(n - 1, start, tmp, finish);

    finish = add_head(finish, get(start, 0));
    start = del_head(start);

    tower_of_hanoi(n - 1, tmp, finish, start);

    printf("\nPosition:\nStart:\n");
    linked_print(start);
    printf("Finish:\n");
    linked_print(finish);
    printf("Tmp:\n");
    linked_print(tmp);
}

void linked_free(LinkedList* l) {
    while (l->next != NULL) l = l->next;

    while (l->prev != NULL) {
        LinkedList* tmp = l;
        l = l->prev;
        free(tmp);
    }
}












