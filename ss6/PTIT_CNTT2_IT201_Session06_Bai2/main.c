#include <stdio.h>

int fibonacci(int n) {
    if (n==0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = n-1;i>=0; i--) {
        printf("%d\t", fibonacci(i));
    }
    return 0;
}