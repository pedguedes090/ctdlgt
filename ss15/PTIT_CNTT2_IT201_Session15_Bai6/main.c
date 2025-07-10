#include <stdio.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}
int isQueueFull(Queue* q) {
    return q->rear == MAX - 1;
}
int isQueueEmpty(Queue* q) {
    return q->front > q->rear;
}
void enQueue(Queue* q, int x) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = x;
}
int deQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;

    }
    return q->data[q->front++];
}
int checkQueue(Queue* q) {
    Queue temp =*q;

    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return 0;
    }
    int prev = deQueue(&temp);
    while (!isQueueEmpty(&temp)) {
        int curr = deQueue(&temp);
        if (curr - prev!=1) {
            return 0;
        }
        prev = curr;
    }
    return 1;
}
void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->data[i]);
    }
}

int main(void) {
    Queue q;
    initQueue(&q);
    for (int i = 0; i < MAX; i++) {
        int x;
        scanf("%d", &x);
        enQueue(&q, x);
    }
    if (checkQueue(&q)) {
        printf("true\n");
    }else {
        printf("false\n");
    }
    return 0;
}