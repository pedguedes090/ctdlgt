#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node *right;
}Node;
typedef struct Queue {
    Node* data[100];
    int front;
    int rear;
}Queue;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Cap phat o nho that bai\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void intQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}
int isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}
void enQueue(Queue* q, Node* node) {
    if (q->rear<100) {
        q->data[q->rear++] = node;
    }
}
Node* deQueue(Queue* q) {
    if (!isQueueEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}

void While(int i);

void insertNode(Node * root, int value) {
    if (root == NULL) {
        return;
    }
    // tao hang doi
    Queue q;
    intQueue(&q);
    // them node goc vao hang doi
    enQueue(&q, root);
    //ktra : lay node trong hang doi ra, neu ben trai==NULL-> them vao? phai==NULL-> them vao
    while(!isQueueEmpty(&q)) {
        Node* curr = deQueue(&q);
        if (curr->left == NULL) {
            printf("Them thanh cong\n");
            curr->left = createNode(value);
            return;
        }else {// khong thi them tiep vao hang doi
            enQueue(&q, curr->left);
        }
        if (curr->right == NULL) {
            printf("Them thanh cong\n");
            curr->right = createNode(value);
            return;
        }else {
            enQueue(&q, curr->right);
        }
    }
}
void display(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}
int main(void) {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    int x;
    scanf("%d", &x);
    insertNode(root, x);

    display(root);
    return 0;
}