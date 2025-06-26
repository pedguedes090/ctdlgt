#include <stdio.h>

int printflog(int n) {
    printf("%d\n", n);
    n--;
    if (n==0) {
        return 1;
    }
    printflog(n);
}
int main(void) {
    int n=10;
    printflog(n);

}