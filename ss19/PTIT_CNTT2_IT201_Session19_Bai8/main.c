#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Cap phat o nho that bai\n");
        return NULL;
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(Node* node) {
    if(node == NULL) {
        return 0;
    }
    height(node->left);
    height(node->right);
    return 1+(height(node->left)>height(node->right) ? height(node->left) : height(node->right));
}
int main(void) {
    Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->left->right->left=createNode(6);
    printf("Chieu cao cua cay la: %d", height(root));
    return 0;
}