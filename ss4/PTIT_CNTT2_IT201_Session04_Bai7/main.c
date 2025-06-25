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
    for (int i = 0; i <= n/2; i++) {
        if (arr[i]==arr[n-i-1]) {
            printf("cap doi xung %d ", arr[i]);
        }
    }
    free(arr);
    return 0;
}
