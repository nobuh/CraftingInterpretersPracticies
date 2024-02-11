// DoublyLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *data;
    struct node *prev;
    struct node *next;
} Node;

typedef struct {
    Node *head;
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

List *createList() {
    List *new = malloc(sizeof(List));
    if (new != NULL) {
        new->head = createNode("", NULL, NULL);
        if (new->head == NULL) {
            free(new);
            return NULL;
        }
    }
    return new;
}

void printList(List *ls) {
    for (Node *n = ls->head->next; n != NULL; n = n->next) {
        printf("%s\n", n->data);
    }
}

void insertAfter(Node *at, char *data) {
    Node *new = createNode(data, at, at->next);
    if (at->next != NULL) {
        new->next->prev = new;
    }
    at->next = new;
}

Node *search(List *ls, char *target) {
    for (Node *n = ls->head->next; n != NULL; n = n->next) {
        if (!strcmp(n->data, target)) {
            return n;
        }
    }
    return NULL;
}

void deleteAt(Node *at) {
    if (at->prev != NULL) {
        at->prev->next = at->next;
    }
    if (at->next != NULL) {
        at->next->prev = at->prev;
    }
    free(at);
}

int main() {
    List *ls = createList();

    printf("-- init list --\n");
    insertAfter(ls->head, "1st");
    insertAfter(ls->head->next, "2nd");
    insertAfter(ls->head->next->next, "3rd");
    printList(ls);

    printf("-- search and delete it --\n");
    Node *found = search(ls, "2nd");
    if (found != NULL) {
        printf("found: %s\n", found->data);
    }
    deleteAt(found);

    printf("-- result --\n");
    printList(ls);

    return 0;
}