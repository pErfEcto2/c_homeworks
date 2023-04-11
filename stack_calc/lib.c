#include "lib.h"


void node_print(Node* node) {    
    while (node != NULL) {
        printf("%f %c\n", node->x, node->operation);
        node = node->next;
    }
}

Node* push(Node* node, double x, char oper) {
    if (node->x == 0 && node->operation == '\0') {
        node->x = x;
        node->operation = oper;
        node->next = NULL;
        return node;
    }

    Node* tmp = malloc(sizeof(Node));
    if (tmp == NULL)
        exit(1);
    
    tmp->next = node;
    tmp->x = x;
    tmp->operation = oper;
    return tmp;
}

Node* del_head(Node* node) {
    if (node == NULL) return NULL;
    if (node->next == NULL) {
        free(node);
        return NULL;
    }
    Node* tmp = node->next;
    free(node);
    return tmp;
}

Node get(Node* node, int n) {
    int i;
    for (i = 0; i < n; i++) {
        node = node->next;
    }
    return *node;
}

Node pop(Node** node) {
    Node res = get(*node, 0);
    *node = del_head(*node);
    return res;
}

int len(Node* n) {
    int res = 0;
    if (n == NULL) return 0;

    if (n->x == 0 && n->operation == '\0')
        return 0;
    
    while (n != NULL) {
        res++;
        n = n->next;
    }
    return res;
}
