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
int isEmpty(Queue* q) {
    return q->size == 0;
}
void printQueue(Queue* q) {
    for (int i = q->front; i < q->size; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}
int deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->array[q->front];
    q->front++;
    return value;

}
int main(void) {
    printf("Hello, World!\n");
    Queue q = createQueue(5);
    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    }else {
        printf("Queue is not empty\n");
    }
    for (int i = q.front; i < 5; i++) {
        enQueue(&q, i);
    }
    int x =deQueue(&q);
    printf("%d\n", x);
    printQueue(&q);

    return 0;
}