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
Node* swap(Node* head) {
    Node* newHead = head->next;
    Node* prev =NULL;
    Node* curr =head;
    while (curr != NULL&&curr->next != NULL) {
        Node* nextPair = curr->next->next;
        Node* second = curr->next;

        second->next = curr;
        curr->next = nextPair;

        if (prev != NULL) {
            prev->next = second;

        }
        prev = curr;
        curr = nextPair;
    }
    return newHead;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
    head = swap(head);
    printList(head);
    return 0;
}