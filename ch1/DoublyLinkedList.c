// DoublyLinkedList.c
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char *data;
    struct node *prev;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} List;

Node *createNode(char *data, Node *prev, Node *next) {
    Node *new = malloc(sizeof(Node));
    if (new != NULL) {
        new->data = data;
        new->prev = prev;
        new->next = next;
    }
    return new;
}

int main() {
    char s[] = "Hello";
    printf("%s\n", createNode(s, NULL, NULL)->data);

    return 0;
}