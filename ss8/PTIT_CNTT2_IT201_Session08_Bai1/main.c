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
    int number;
    printf("vui long nhap so can tim kiem");
    scanf("%d", &number);
    for (int i =0;i<n;i++){
        if (arr[i] == number) {
            printf("vi tri thu %d",i+1);
            break;
        }
    }
    return 0;
}
