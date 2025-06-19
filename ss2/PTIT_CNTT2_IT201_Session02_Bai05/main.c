#include <stdio.h>

int main(void) {
    int n;
    int arr[100];
    int pos;
    do {
        printf("nhap so phan tu cua mang (0 < n <= 100) ");
        scanf("%d", &n);
    }while(n < 1 || n > 100);
    for (int i =0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    do {
        printf("vui long nhap vi tri muon xoa");
        scanf("%d", &pos);
    }while(pos < 0||pos >=n);
    for (int i=pos;i<n;i++){
        arr[i] = arr[i+1];
    };
    n--;
    for (int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}