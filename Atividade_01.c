//ALUNO: LUCAS MARCO POROROCA BRANDÃO - 26142404

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertinorder(Node** head, int data) {
    Node* newNode = createNode(data);
    
    
    if (*head == NULL || (*head)->data > data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertinorder(&head, 5);
    insertinorder(&head, 2);
    insertinorder(&head, 8);
    insertinorder(&head, 1);
    insertinorder(&head, 7);

    printList(head);

    return 0;
}