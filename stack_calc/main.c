#include "lib.h"


int main(int argc, char* argv[]) {
    srand(time(0));
    
    char c;
    double res = 0;
    Node* numbers = malloc(sizeof(Node));
    Node* operations = malloc(sizeof(Node));

    if (numbers == NULL || operations == NULL)
        exit(1);

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            break;
        else if (c == ' ')
            continue;
        
        switch (c) {
            case '+':
            case '-':
                operations = push(operations, 0, c);
                break;
            
            case '*':
            case '/':
                char prev_oper = get(operations, 0).operation;
                if (prev_oper != '+' && prev_oper != '-') {
                    operations = push(operations, -1, c);
                    continue;
                }
                double a = pop(&numbers).x;
                double b = pop(&numbers).x;
                
                if (c == '*') a *= b;
                else a /= b;

                numbers = push(numbers, a, '\0');
                break;

            case '0'...'9':
                numbers = push(numbers, c - '0', 't');
                break;
            
            default:
                printf("invalid chaarcter: %c\n", c);
                exit(1);
        }

        printf("Numbers:\n");
        node_print(numbers);
        printf("Operations:\n");
        node_print(operations);
        printf("\n\n");
    }

    while (len(operations) && len(numbers)) {
        double a = pop(&numbers).x;
        double b = pop(&numbers).x;
        char oper = pop(&operations).operation;
        b = (oper == '+') ? b + a : b - a;
        
        if (len(operations) == 0) {
            res = b;
            break;
        }

        numbers = push(numbers, b, 't');
        printf("%d %d\n", len(numbers), len(operations));
    }

    printf("res: %f\n", res);

    if (len(numbers)) free(numbers);
    if (len(operations)) free(operations);

    return 0;
}
