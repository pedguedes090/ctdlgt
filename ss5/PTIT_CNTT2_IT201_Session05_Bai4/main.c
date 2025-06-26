#include <stdio.h>
int sum(int a, int b) {
    if (a>b) {
        return 0;
    }
    return a +sum(a+1,b);
}
int main(void) {
    int a;
    int b;
    printf("nhap so bat dau");
    scanf("%d", &a);
    printf("nhap so ket thuc");
    scanf("%d", &b);
    if (a<0||a>b||b<0) {
        printf("khong hop le");
    }
    printf("%d\n", sum(a,b));
    return 0;
}