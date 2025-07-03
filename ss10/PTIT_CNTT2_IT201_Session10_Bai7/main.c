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
void sortList(Node* head) {
    int swapped;
    Node* ptr1;
    Node* lptr =NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }while (swapped);

}
int main(void) {
    Node* head = createNode(7);
    Node* node2 = createNode(2);
    Node* node3 = createNode(9);
    Node* node4 = createNode(4);
    Node* node5 = createNode(1);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(head);
    sortList(head);
    printList(head);
    return 0;
}