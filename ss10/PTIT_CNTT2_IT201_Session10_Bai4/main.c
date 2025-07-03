#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void printList(Node* node) {
    Node* temp = node;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;

    }
    printf("\n");
}
Node* deleteNode(Node* head) {
    Node* curr=head;
    if (head==NULL) {
        free(head);
        return NULL;
    }
    while (curr->next->next!=NULL) {
        curr=curr->next;
    }
    free(curr->next);
    curr->next=NULL;
    return head;
}
int main(void) {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    head = deleteNode(head);
    printList(head);
    return 0;
}