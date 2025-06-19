#include <stdio.h>
void printDouble(int n ) {
    int i =1;
    while(i<n) {
        printf("%d\n",i);
        i *=2;
    }
}
int main() {
    int n =100;
    printDouble(n);
}
// độ phức tạp là o(logn)