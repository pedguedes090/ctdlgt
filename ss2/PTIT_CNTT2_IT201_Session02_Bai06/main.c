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
        printf("vui long nhap vi tri muon chen ");
        scanf("%d", &pos);
        printf("vui long nhap gia tri ban muon");
        scanf("%d", &value);
    }while(pos < 1 || pos > n);
    for (int i =n;i>pos;i--) {
        arr[i] = arr[i-1];
    };
    arr[pos]=value;
    n++;
    for (int i =0;i<n;i++) {
        printf("%d ",arr[i]);
    }

    return 0;
}