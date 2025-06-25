#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int min=0;
    int indexmin;
    printf("vui long nhap phan tu");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            indexmin = i;
        }
    }
    printf("%d,indexmin");
    return 0;
}
