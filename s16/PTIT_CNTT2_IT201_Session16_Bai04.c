//PTIT_CNTT1_IT201_Session16_Bai04

#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
    int cap;
}Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    q->cap = 3;
    return q;
}
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
Queue* enQueue(Queue* q, int data) {
    if (q->size>=q->cap) {
        printf("full\n");
        return q;
    }
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    return q;
}
void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("NULL\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void top(Queue* q) {
    if (q->front == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d",q->front->data);
}
void check(Queue* q) {
    if (q->front == NULL) {
        printf("empty queue\n");
    }
    printf("%d",q->front->data);
}
int main() {
    Queue* q = createQueue();

    printQueue(q);
    check(q);

}


