#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void delete(int key) {
    if (head == NULL) return;
    struct Node *current = head, *prev = NULL;
    while (current->data != key) {
        if (current->next == head) {
            printf("Key not found\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    if (current == head) {
        prev = head;
        while (prev->next != head) prev = prev->next;
        head = head->next;
        prev->next = head;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }
}

void display() {
    struct Node *temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    printf("Original Circular Linked List: ");
    display();
    delete(3);
    printf("Circular Linked List after deleting node with key 3: ");
    display();
    return 0;
}

