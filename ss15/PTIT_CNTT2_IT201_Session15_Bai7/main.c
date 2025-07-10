#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[30];
}Customer;
typedef struct {
    Customer data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isQueueFull(Queue* q) {
    return ((q->rear + 1) % MAX == q->front);
}
int isQueueEmpty(Queue* q) {
    return q->front == -1;
}
void enQueue(Queue* q, char name[]) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    strncpy(q->data[q->rear].name, name,30);
    q->data[q->rear].name[30] = '\0';
    printf("da them khach hang %s",name);
}
void deQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("dang phuc vu khach hang %s",q->data[q->front].name);
    if (q->front == q->rear) {
        q->front = q->rear = -1;

    }else {
        q->front = (q->front + 1) % MAX;
    }
}

void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("khach hang dang cho\n");
    int i = q->front;
    int count = 1;
    while (1) {
        printf("  %d. %s\n", count++, q->data[i].name);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
}

int main(void) {
    Queue q;
    initQueue(&q);
    int choice;
    char name[30];
    while (1) {
        printf("\n vui long nhap\n 1them khach hang\n2 phuc vu khach hang \n 3 hien thi danh sach khach hang cho \n 4 thoat");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("NHap ten khach hang: ");
                fgets(name, 30, stdin);
                name[strlen(name) - 1] = '\0';
                enQueue(&q, name);
                break;
            case 2:
                deQueue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("thoat ");
                exit(0);
            default:
                printf("lua chon khong hop le");
        }

    }

    return 0;
}