#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
}

void deleteNode(struct Node* del) {
    if (head == NULL || del == NULL)
        return;

    if (head == del)
        head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void display() {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtEnd(1);
    insertAtBeginning(2);
    insertAtEnd(3);
    insertAtBeginning(4);
    insertAtEnd(5);

    printf("Original ");
    display();

    deleteNode(head->next);
    printf("List after deleting node at position 2: ");
    display();

    return 0;
}
