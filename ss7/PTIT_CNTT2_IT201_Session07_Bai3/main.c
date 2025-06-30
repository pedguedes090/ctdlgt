#include <stdio.h>
#include <stdlib.h>

int sort(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        int key = arr[i];
        int j=i-1;
        while (j>=0&&arr[j]>key) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int main(void) {
    int n;
    printf("vui long nhap so phan tu");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
