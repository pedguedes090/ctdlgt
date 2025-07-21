#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node*createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Cap phat o nho that bai\n");
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void postOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main(void) {
    Node* root=createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Postorder: \n");
    postOrder(root);
    return 0;
}