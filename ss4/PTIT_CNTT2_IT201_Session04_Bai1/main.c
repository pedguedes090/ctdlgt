#include <stdio.h>

int main(void) {
    int arr[];
    int n;
    printf("vui long nhap so luong phan tu");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",arr[i]);
    }
    int a;
    printf("vui long nhap phan tu da tim kiem");
    scanf("%d",&a);
    for (int i = 0; i < n; i++) {
        if (arr[i]==a) {
            printf("%d,",arr[i]);
            return 0;
        }
    }
    return 0;
}