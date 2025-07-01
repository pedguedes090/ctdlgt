#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("vui long nhap so phan tu");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }
    int number;
    printf("vui long nhap so can tim kiem");
    scanf("%d", &number);
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == number) {
            printf("vi tri thu %d ", number+1);
            break;
        }
        if (arr[mid] > number) {
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return 0;
}
