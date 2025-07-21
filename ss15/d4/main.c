#include <stdio.h>
int foo(int n) { return (n == 0) ? 0 : n + foo(n - 1); }

int main(void) {
    printf("%d\n", foo(4));
    return 0;
}