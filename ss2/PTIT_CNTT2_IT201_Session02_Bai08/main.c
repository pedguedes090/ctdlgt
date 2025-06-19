#include <stdio.h>

int main(void) {
    int n;
    int arr[100];
    do {
        printf("nhap so phan tu cua mang (0 < n <= 100) ");
        scanf("%d", &n);
    }while(n < 1 || n > 100);
    for (int i =0;i<n;i++) {
        scanf("%d", &arr[i]);
    };
    for (int i =0;i<n;i++) {
        int flag =1;
        for (int j =i+1;j<n;j++) {
            if (arr[i]<arr[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}