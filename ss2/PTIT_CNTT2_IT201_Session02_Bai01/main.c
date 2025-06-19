#include <stdio.h>

int main(void) {
    int n;
    int arr[100];
    int max;
    do {
        printf("nhap so phan tu cua mang (0 < n <= 100) ");
        scanf("%d", &n);
    }while(n < 1 || n > 100);
    for (int i =0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    for (int i =0;i<n;i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("%d", max);
}