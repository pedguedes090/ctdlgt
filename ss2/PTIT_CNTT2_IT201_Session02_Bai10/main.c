#include <stdio.h>

int main(void) {
    int n;
    int arr[100];
    int arr2[100];

    do {
        printf("nhap so phan tu cua mang (0 < n <= 100) ");
        scanf("%d", &n);
    }while(n < 1 || n > 100);
    for (int i =0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    for (int i =0;i<n;i++) {
        int count=0;
        for (int j =0;j<n;j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        arr2[i] = count;
    }
    for (int i = 0; i < n; i++) {
        if (arr2[i] > 0) {
            printf("Phan tu %d xuat hien %d lan\n", arr[i], arr2[i]);
            // đánh dấu để khỏi in lại
            for (int j = 0; j < n; j++) {
                if (arr[j] == arr[i]) {
                    arr2[j] = 0;
                }
            }
        }
    }
    return 0;
}