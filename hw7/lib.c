#include "lib.h"


void linked_print(LinkedList* l) {    
    while (l != NULL) {
        printf("%d\n", l->x);
        l = l->next;
    }
}

void add_tail(LinkedList* l, int value) {
    if (l->next == NULL) {
        LinkedList* tmp = malloc(sizeof(LinkedList));
        
        tmp->x = value;
        tmp->next = NULL;
        tmp->prev = l;
        l->next = tmp;
    }
    else {
        add_tail(l->next, value);
    }
}

LinkedList* add_head(LinkedList* l, int value) {
    LinkedList* tmp = malloc(sizeof(LinkedList));

    if (tmp == NULL)
        exit(1);
    
    tmp->next = l;
    l->prev = tmp;
    tmp->prev = NULL;
    tmp->x = value;
    l->prev = tmp;
    return tmp;
}

LinkedList* del_head(LinkedList* l) {
    if (l == NULL) return NULL;
    else if (l->next == NULL) {
        free(l);
        l = NULL;
        return NULL;
    }
    LinkedList* tmp = l->next;
    tmp->prev = NULL;
    free(l);
    l = NULL;
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
    while (l != NULL) {
        res++;
        l = l->next;
    }
    return res;
}

void swap(LinkedList* l, int first, int second) {
    if (first >= len(l) || second >= len(l)) exit(3);
    LinkedList* tmp = l;
    int i;
    for (i = 0; i < first; i++) {
        if (l != NULL) l = l->next;
        else exit(2);
    }

    for (i = 0; i < second; i++) {
        if (tmp != NULL) tmp = tmp->next;
        else exit(2);
    }

    int temp = l->x;
    l->x = tmp->x;
    tmp->x = temp;
}

int get(LinkedList* l, int n) {
    if (n > len(l)) exit(3);
    int i;
    for (i = 0; i < n; i++) {
        l = l->next;
    }
    return l->x;
}

void select_sort(LinkedList* l) {
    if (l == NULL || l->next == NULL) return;

    int n = len(l), i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (get(l, j) < get(l, i))
                swap(l, i, j);
        }
    }
}

void list_fprintf(LinkedList* l, char path[]) {
    FILE* f = fopen(path, "w");
    if (f == NULL)
        exit(4);
    
    int i, n = len(l);
    for (i = 0; i < n; i++) {
        fprintf(f, "%d\n", l->x);
        l = l->next;
    }

    fclose(f);
}

LinkedList* list_fscanf(char path[]) {
    FILE* f = fopen(path, "r");
    if (f == NULL)
        exit(5);
    
    LinkedList* tmp = malloc(sizeof(LinkedList));
    tmp->prev = NULL;
    tmp->next = NULL;
    int tmp_x, i;
    
    for (i = 0; fscanf(f, "%d\n", &tmp_x) != EOF; i++) {
        if (i == 0) tmp->x = tmp_x;
        else add_tail(tmp, tmp_x);
    }

    fclose(f);
    return tmp;
}
