#include <stdio.h>

int main(void) {
    int n;
    int arr[100];
    int num;
    do {
        printf("nhap so phan tu cua mang (0 < n <= 100) ");
        scanf("%d", &n);
    }while(n < 1 || n > 100);
    for (int i =0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    printf("nhap mot so nguyen bat ki");
    scanf("%d", &num);
    for (int i =0;i<n;i++) {
        for (int j =i+1;j<n;j++) {
            if (arr[i]+arr[j] == num) {
                printf("%d %d",arr[i] ,arr[j]);
            }
        }
    }
    return 0;
}