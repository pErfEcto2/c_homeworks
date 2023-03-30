#include "lib.h"


void linked_print(LinkedList* l) {    
    while (l != NULL) {
        printf("%d %s\n", l->x, l->name);
        l = l->next;
    }
}

LinkedList* add_tail(LinkedList* l, int x, char name[]) {
    if (l->x == 0 && !strcmp(l->name, "\0")) {
        l->x = x;
        memcpy(l->name, name, STR_LEN);
        l->next = NULL;
        l->prev = NULL;
        return l;
    }

    LinkedList* res = l;
    while (l->next != NULL) l = l->next;

    LinkedList* tmp = malloc(sizeof(LinkedList));
    tmp->x = x;
    memcpy(tmp->name, name, STR_LEN);
    tmp->prev = l;
    l->next = tmp;
    return res;
}

LinkedList* add_head(LinkedList* l, int x, char name[]) {
    if (l->x == 0 && !strcmp(l->name, "\0")) {
        l->x = x;
        memcpy(l->name, name, STR_LEN);
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
    tmp->x = x;
    memcpy(tmp->name, name, STR_LEN);
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
    int i, min, max;
    min = (first <= second) ? first : second;
    max = first + second - min;
    
    for (i = 0; i < min; i++) {
        if (l != NULL) l = l->next;
        else exit(2);
    }
    LinkedList* tmp = l;

    for (i = 0; i < max - min; i++) {
        if (l != NULL) l = l->next;
        else exit(2);
    }

    LinkedList temp = *l;
    l->x = tmp->x;
    tmp->x = temp.x;
    memcpy(l->name, tmp->name, STR_LEN);
    memcpy(tmp->name, temp.name, STR_LEN);   
}

LinkedList get(LinkedList* l, int n) {
    if (n > len(l)) exit(3);
    int i;
    for (i = 0; i < n; i++) {
        l = l->next;
    }
    return *l;
}

void select_sort(LinkedList* l) {
    if (l == NULL || l->next == NULL) return;

    int n = len(l), i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (get(l, j).x < get(l, i).x)
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
        fprintf(f, "%d %s\n", l->x, l->name);
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
    char s[STR_LEN] = {'\0'};
    
    for (i = 0; fscanf(f, "%d %s\n", &tmp_x, s) != EOF; i++) {
        if (i == 0) {
            tmp->x = tmp_x;
            memcpy(tmp->name, s, STR_LEN);
        }
        else add_tail(tmp, tmp_x, s);
    }

    fclose(f);
    return tmp;
}
