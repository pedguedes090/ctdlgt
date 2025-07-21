#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
typedef struct Queue {
    int front;
    int rear;
}Queue;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node==NULL) {
        printf("Cap phat o nho that bai\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int inOrder(Node * root, int x) {
    if (root==NULL) {

        return 0;
    }
    if (inOrder(root->left,  x)) return 1;
    if (root->data==x) return 1;
    if (inOrder(root->right, x)) return 1;
    return 0;
}
int main(void){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    int x;
    scanf("%d",&x);
    if(inOrder(root,x)) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    return 0;
}