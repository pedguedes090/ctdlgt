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
Node* sortList(Node* head) {
    Node* temp = head;
    int swaped;
    Node* ptr1;
    Node* lptr=NULL;
    do {
        swaped =0;
        ptr1 = temp;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swaped =1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }while(swaped);
    return head;

}
int main(void) {
    Node *head = createNode(2);
    Node *node1 = createNode(9);
    Node *node2 = createNode(3);
    Node *node3 = createNode(9);
    Node *node4 = createNode(1);

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
head = sortList(head);
    printList(head);
    return 0;
}