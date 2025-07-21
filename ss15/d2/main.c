#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//B1 khoi tao struct
typedef struct Song {
    char title[100];
}Song;
typedef struct Node {
    Song song;
    struct Node *next;
}Node;
typedef struct {
    Node* front;
    Node* rear;
} Queue;
typedef struct {
    Node* top;
} Stack;
// ham tao node moi
Node* createNode(char* title ) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->song.title, title);
    newNode->next = NULL;
    return newNode;
}
//B2 cac ham thao tac
// thao tac voi hang doi
//khoi tao hang doi
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}
//them moi phan tu vao trong hang doi
void enQueue(Queue* q,char* title) {
    Node* newNode = createNode(title);
    if (q->rear ==NULL) {
        q->front = newNode;
        q->rear = newNode;
    }else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int deQueue(Queue* q,Song* song) {
    if (q->front == NULL) {
        return 0;
    }
    Node* temp = q->front;
    *song = temp->song;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return 1;
}
// cac ham voi stack
// khoi tao stack
void initStack(Stack* s) {
    s->top = NULL;
}
void push(Stack* s,Song song) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->song = song;
    newNode->next=s->top;
    s->top = newNode;
}
int pop(Stack* s,Song* element) {
    if (s->top == NULL) {
        return 0;
    }
    Node* temp = s->top;
    *element = temp->song;
    s->top = s->top->next;
    free(temp);
    return 1;
}
void printHistory(Stack* s) {
    Node* curr = s->top;
    printf("lich su phat nhac ");
    if (!curr) {
        printf("khong co bai hat nao trong lich sư \n");
        return;
    }
    while (curr) {
        printf(" %s ",curr->song.title);
        curr = curr->next;
    }
}

int main(void) {
    Queue q;
    Stack s;
    initQueue(&q);
    initStack(&s);
    int choice;
    char title[100];
    Song song;
    while (1) {
        printf("1.ADD \n");
        printf("2. play next \n");
        printf("3. play prev \n");
        printf("4. history \n");
        printf("5. exit\n");
        printf("chon chuc nang \n");
        scanf("%d",&choice);
        getchar();
        switch (choice) {
            case 1:
                printf("nhap ten bai hat");
                fgets(title,100,stdin);
                title[strlen(title)-1] = '\0';
                enQueue(&q,title);
                printf("da them %s \n", title);
                break;
            case 2:
                if (deQueue(&q, &song)) {
                    printf("Đang phát: %s\n", song.title);
                    push(&s, song);
                } else {
                    printf("Không có bài hát nào trong hàng đợi!\n");
                }
                break;

            case 3:
                if (pop(&s, &song)) {
                    printf("Phát lại: %s\n", song.title);
                } else {
                    printf("Không có bài hát nào trong lịch sử!\n");
                }
                break;

            case 4:
                printHistory(&s);
                break;

            case 5:
                printf("Thoát chương trình.\n");
                return 0;

            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    }

    return 0;
}