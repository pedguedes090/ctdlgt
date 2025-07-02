#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
Node* createNote(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Node* deleteNodeIndex(Node* head,int pos) {
    Node* deleteNode =head;
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    for (int i = 1; i < pos-1; i++) {
        deleteNode =deleteNode->next;
    }
    Node* temp = deleteNode->next;
    deleteNode->next = temp->next;
    free(temp);
    return head;

}
int main(void) {
    Node* head = createNote(10);
    Node* node2 = createNote(20);
    Node* node3 = createNote(30);
    Node* node4 = createNote(40);
    Node* node5 = createNote(50);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    int position;
    printf("Enter the position : ");
    scanf("%d", &position);
    head = deleteNodeIndex(head, position);
    return 0;
}