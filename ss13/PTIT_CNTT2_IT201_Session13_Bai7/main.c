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
char pop(Stack* s) {
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
int checkMiss(char open,char close) {
    return (open == '(' && close == ')')||(open == '{' && close == '}')||(open == '[' && close == ']');
}
int checkBracket(char expr[]) {
    Stack s;
    initStack(&s);
    for (int i=0;expr[i]!='\0';i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        }else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s)||!checkMiss(pop(&s),c)) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}
int main(void) {
    Stack s;
    initStack(&s);
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';
    if (checkBracket(str)) {
        printf("true");

    }else {
        printf("false");
    }
    return 0;
}