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

void findMidNode(Node* head) {
    int count = 0;
    Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    if (count ==0) {
        printf("danh sach rong");
        return;
    }
    int mid=count/2+1;
    curr = head;
    int pos = 1;
    while (pos<mid) {
        curr = curr->next;
        pos++;
    }
    printf("node %d: %d \n",mid,curr->data);
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
    printList(head);
    findMidNode(head);
    return 0;
}