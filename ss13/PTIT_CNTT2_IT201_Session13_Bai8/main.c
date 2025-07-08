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
int check(char expr[]) {
    Stack s;
    initStack(&s);
    for(int i = 0; expr[i] !='\0'; i++) {
        char c = expr[i];
        if (isdigit(c)) {
            push(&s, c - '0');
        }else if (c == '+'||c =='-'||c == '*'||c == '/') {
            int b = pop(&s);
            int a = pop(&s);
            int result;
            switch(c) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;


            }
            push(&s, result);
        }
    }
    return pop(&s);
}
int main(void) {
    Stack s;
    initStack(&s);
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';
    int result = check(str);
    printf("Result: %d\n", result);
    return 0;
}