#include <stdio.h>

int main(void) {
    int n;
    int arr[100];
    int pos;
    int value;
    do {
        printf("nhap so phan tu cua mang (0 < n <= 100) ");
        scanf("%d", &n);
    }while(n < 1 || n > 100);
    for (int i =0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    do {
        printf("nhap vi tri muon sua");
        scanf("%d", &pos);
    }while(n < 1 || n > 100);
    printf("vui long nhap gia tri muon sua doi");
    scanf("%d", &value);
    arr[pos] = value;
    for (int i =0;i<n;i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}