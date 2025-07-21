#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Cap phat bo nho that bai \n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int main(void) {
    int n;
    scanf("%d", &n);
    Node* root = createNode(n);
    printf("node={\n data: %d,\n left->%d,\n right->%d\n}", root->data,root->left,root->right);
    return 0;
}