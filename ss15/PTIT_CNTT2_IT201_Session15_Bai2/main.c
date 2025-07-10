#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int front;
    int rear;
    int maxSize;
    int size;
} Queue;
Queue createQueue(int maxSize) {
    Queue q;
    q.array = malloc(maxSize * sizeof(int));
    q.front = 0;
    q.rear = -1;
    q.maxSize = maxSize;
    q.size = 0;
    return q;
}
void enQueue(Queue* q, int value) {
    if (q->size==q->maxSize) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
    q->size++;
}
void printQueue(Queue* q) {
    for (int i = q->front; i < q->size; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}
int main(void) {
    printf("Hello, World!\n");
    Queue q = createQueue(5);
    for (int i = q.front; i < 5; i++) {
        enQueue(&q, i);
        printQueue(&q);
    }
    enQueue(&q, 10);
    return 0;
}