
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int val) {
    Node* n = malloc(sizeof *n);
    if (!n) return NULL;
    n->data = val;
    n->next = NULL;
    return n;
}

void add_at_tail(Node **head, int val) {
    Node *n = create_node(val);
    if (!n) return;
    if (*head == NULL) {
        *head = n;
        return;
    }
    Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

void print_list(const Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void free_list(Node *head) {
    while (head) {
        Node *t = head->next;
        free(head);
        head = t;
    }
}

void insert_sort(Node **head) {
    Node *sorted = NULL;
    Node *current = *head;
    while (current) {
        Node *next = current->next;
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *s = sorted;
            while (s->next && s->next->data <= current->data) {
                s = s->next;
            }
            current->next = s->next;
            s->next = current;
        }
        current = next;
    }
    *head = sorted;
}

int main(void) {
    int n;
    printf("Ingresa el tamano del arreglo: ");
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;

    Node *head = NULL;
    printf("Ingresa los elementos del arreglo:\n");
    for (int i = 0; i < n; ++i) {
        int v;
        printf("Elemento %d: ", i + 1);
        if (scanf("%d", &v) != 1) { free_list(head); return 1; }
        add_at_tail(&head, v);
    }

    insert_sort(&head);

    printf("Lista ordenada:\n");
    print_list(head);

    while (1) {
        char opc;
        printf("Desea agregar un nuevo elemento (s/n): ");
        if (scanf(" %c", &opc) != 1) break;
        if (opc == 'n' || opc == 'N') break;
        if (opc == 's' || opc == 'S') {
            int val;
            printf("Ingrese el valor: ");
            if (scanf("%d", &val) != 1) break;
            add_at_tail(&head, val);
            insert_sort(&head);
            printf("Lista actualizada y ordenada:\n");
            print_list(head);
        }
    }

    free_list(head);
    return 0;
}