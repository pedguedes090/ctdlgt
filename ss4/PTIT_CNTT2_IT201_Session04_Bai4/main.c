#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int number;
    printf("vui long nhap so phan tu");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int a;
    printf("vui long nhap so can tim kiem");
    scanf("%d", &a);

    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            number=i;
        };

    }
    printf("%d", number);
    free(arr);
    return 0;
}
