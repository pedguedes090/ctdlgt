#include <stdio.h>

int sum(int n) {
    if (n==1) {
        return 1;
    }
    return sum(n-1) + n;
}
int main(void) {
    int n =3;
    printf("%d\n", sum(n));
    printf("Hello, World!\n");
    return 0;
}