#include <stdio.h>
#include <stdlib.h>

int sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    int *even = (int*)malloc(sizeof(int) * n);
    int *odd = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int countEven = 0, countOdd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i]%2 == 0) {
            even[countEven] = arr[i];
            countEven++;
        }else {
            odd[countOdd] = arr[i];
            countOdd++;
        }
    }
    sort(even, countEven);
    sort(odd, countOdd);
    for (int i = 0; i < countEven; i++) {
        printf("%d ", even[i]);
    }
    for (int i = 0; i < countOdd; i++) {
        printf("%d ", odd[i]);
    }
    free(arr);
    free(even);
    free(odd);
    return 0;
}
