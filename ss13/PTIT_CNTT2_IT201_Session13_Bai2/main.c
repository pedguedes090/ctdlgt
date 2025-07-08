#include <stdio.h>

#define MAX 5
typedef struct {
    int elements[MAX];
    int top;
    int cap;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
    s->cap = MAX;
}
int push(Stack *s, int element) {
    if (s->top>=s->cap-1) {
        printf("Stack Overflow\n");
        return 0;
    }
    s->top++;
    s->elements[s->top] = element;
    return 1;
}
void printStack(Stack s) {
    for (int i=0;i<=s.top;i++) {
        printf("%d ", s.elements[i]);
        if (i!=s.top) {
            printf(", ");
        }
    }
    printf("\n top %d \n ", s.top);
    printf("cap %d\n", s.cap);
}
int main(void) {
    Stack s;
    initStack(&s);
    int element;
    printf("Enter a number: ");
    for (int i=0;i<MAX;i++) {
        scanf("%d", &element);
        push(&s, element);
    }
    printStack(s);
    return 0;
}