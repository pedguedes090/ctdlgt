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
Node* addNode(Node* head,int value, int position) {
    Node* newNode = createNote(value);
    Node* temp = head;
    for (int i = 1; i < position-1; i++) {
        temp = temp->next;
    }
    Node* nextNode =temp->next;
    temp->next = newNode;
    newNode->next = nextNode;
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
    int value;
    printf("vui long nhap value");
    scanf("%d", &value);
    int position;
    printf("vui long nhap position");
    scanf("%d", &position);
    addNode(head, value, position);
    return 0;
}