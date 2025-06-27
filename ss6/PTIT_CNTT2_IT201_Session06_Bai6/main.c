#include <stdio.h>
int check(int n,int i) {
    if (i>n) {
        return 0;
    }
    if (i==n) {
        return 1;
    }
    return check(n,i+1)+check(n,i+2);
}
int main(void) {
    int n;
    scanf("%d",&n);
    printf("%d",check(n,0));
    return 0;
}