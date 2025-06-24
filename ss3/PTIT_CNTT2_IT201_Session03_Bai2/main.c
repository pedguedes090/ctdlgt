#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n<=0||n>100) {
        printf("So luong phan tu khong hop le: ");
    }
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Nhap phan tu: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);

    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("phan tu max la %d",&max);
    free(arr);
    return 0;
}