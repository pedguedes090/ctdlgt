#include <stdio.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int top;
}Stack;
void initStack(Stack* s) {
    s->top = -1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack is full\n");
    }else {
        s->data[++s->top] = value;
    }
}
int pop(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];
}
void print(Stack* s) {
    for(int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
}
int main(void) {
    Stack s;
    initStack(&s);
    printf("Nhap vao phan tu cua ngan xep:\n");
    for (int i=0; i<MAX; i++) {
        int x;
        scanf("%d", &x);
        push(&s,x);
    }
    print(&s);
    return 0;
}