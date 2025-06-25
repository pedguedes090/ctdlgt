#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int max=0;
    printf("vui long nhap so luong phan tu");
    int *arr = (int *)malloc(n* sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
       if (arr[i] > max) {
           max = arr[i];
       }
    }
    printf("%d", max);
    return 0;
}
