#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Cap phat o nho that bai\n");
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
typedef struct Queue {
    Node *items[100];
    int front;
    int rear;
}Queue;
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}
int isEmpty(Queue *q) {
    return q->front == q->rear;
}
void enQueue(Queue *q, Node* node) {
    if (q->rear < 100) {
        q->items[q->rear++]=node;
    }
}
Node* deQueue(Queue *q) {
    if (q->front<q->rear) {
        return q->items[q->front++];
    }
    return NULL;
}

void leverOder(Node* root, int x) {
    if (root == NULL) return;
    Queue q;

    initQueue(&q);
    enQueue(&q, root);
    while (!isEmpty(&q)) {
        Node* curr=deQueue(&q);
        if (curr->data==x) {
            printf("true");
            return;
        }
        if (curr->left != NULL) {
            enQueue(&q, curr->left);
        }
        if (curr->right != NULL) {
            enQueue(&q, curr->right);
        }
    }
    printf("False");
}
int main(void) {
    Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    int x;
    printf("findValue: ");
    scanf("%d",&x);
    leverOder(root,x);
    return 0;
}