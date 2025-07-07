#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(int data) {
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
Node* findMidNode(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    temp = head;
    int index = 0;
    while (index < count/2) {
        temp = temp->next;
        index++;
    }
    printf("Node %d : %d\n", index+1,temp->data);
}
int main(void) {
    Node *head = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);

    head->next = node1;
    head->prev = NULL;
    node1->next = node2;
    node1->prev = head;
    node2->next = node3;
    node2->prev = node1;
    node3->next = node4;
    node3->prev = node2;
    node4->next = NULL;
    node4->prev = node3;
    head = findMidNode(head);
    printList(head);
    return 0;
}