#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char data[MAX];
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
int check(char str[]) {
    Stack s;
    initStack(&s);
    int len = strlen(str);
    char str1[MAX];
    int n=0;

    for(int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            str1[n]=tolower(str[i]);
            push(&s, str1[n]);
            n++;
        }

    }
    for(int i = 0; i < n; i++) {
        if (str1[i]!=pop(&s)) {
            return 0;
        }

    }
    return 1;

}
int main(void) {
    Stack s;
    initStack(&s);
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';
    if(check(str)) {
        printf("true");
    }else {
        printf("false");
    }
    return 0;
}