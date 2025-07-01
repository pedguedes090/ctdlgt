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
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        for (; j >=0 && arr[j]>key; j--) {
            arr[j+1] = arr[j];

        }
        arr[j+1]=key;

    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
