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
int lenght(Node* head) {
    int len = 0;
    while (head != NULL) {
        head = head->next;
        len++;
    }
    return len;
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
    printf("danh sach lien ket co so phan tu %d",lenght(head));
    return 0;
}