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
Node* insertNode(Node* head, int pos,int data) {
    Node* temp =head;
    int index = 1;
    while (temp != NULL && index < pos-1) {
        temp = temp->next;
        index++;
    }
    if (temp == NULL) {
        return head;

    }
    Node* newnode=createNode(data);
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next == NULL) {
        temp->next = newnode;
    }
    temp->next = newnode;
    return head;
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

    head = insertNode(head, 3, 1);
    printList(head);
    return 0;
}