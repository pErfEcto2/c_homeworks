#define N 10
#define T 20

typedef struct Node {
	int size;
	struct Node *next;
	struct Node *prev;
} node;
typedef struct nodepointer {
	struct nodepointer *next;
	struct Node **address; 
} pointer;

void pr(node *tmp);
node *add_head(node *head, int hh);
node *del_head(node *head);
pointer *add_head_address(pointer *head, node **address);
int length(node *list);
node *sort(node *head);
node *get(node *list, int n);
void swap(node *a, node *b);
void hanoi_tower(int n, node **head_from, node **head_to, node **head_aux, pointer* adresses);
void printftof(pointer* adresses);
node* printextra(node *head, int len, int i);
void disk(int size);
void prcount(char s, int n);
