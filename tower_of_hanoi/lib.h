#define N 10

typedef struct Node {
	long int data;
	struct Node *next;
	struct Node *prev;
	char s[N];
} node;

void pr(node *tmp);
node *add_head(node *head, int hh);
node *del_head(node *head);
int length(node *list);
node *sort(node *head);
node *get(node *list, int n);
void swap(node *a, node *b);
node *adv_add_head(node *head, int hh, char string[]);
void hanoi_tower(int n, node **head_from, node **head_to, node **head_aux, node **const tower1, node **const tower2, node **const tower3);
void printftof(node *head1, node *head2, node *head3);
node *end(node *head);
node* printextra(node *head, int len, int i);
int max(int a, int b);