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
Node* deleteNodeValue(Node* head, int value) {
    while (head!=NULL&&head->data==value) {
        Node* temp =head;
        head = head->next;
        free(temp);
    }
    Node* curr=head;
    while (curr->next!=NULL) {
        if (curr->next->data==value) {
            Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }else {
            curr=curr->next;
        }
   }
    return head;
}
int main(void) {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(3);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(head);
    int value;
    printf("vui long nhap so muon xoa");
    scanf("%d",&value);
    head = deleteNodeValue(head, value);
    printList(head);
    return 0;
}