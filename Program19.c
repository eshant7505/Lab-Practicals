#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int removed = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return removed;
}

void display(struct Queue *q) {
    if (q->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    display(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    display(&q);

    return 0;
}
