#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("vui long nhap so phan tu");
    scanf("%d", &n);
    int *arr =(int *)malloc (n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int minIndex=i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j]<arr[minIndex]) {
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
