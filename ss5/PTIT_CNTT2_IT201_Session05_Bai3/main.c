#include <stdio.h>

int factorial(int n) {
    if (n==1) {
        return 1;
    }
    return n*factorial(n-1);
}
int main(void) {
    int n=5;
    printf("%d\n", factorial(n));
    printf("Hello, World!\n");
    return 0;
}