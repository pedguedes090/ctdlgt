#include <stdio.h>
#include <stdlib.h>
int partition(int *arr, int low, int high) {
    int p = arr[low];
    int i = low;
    int j = high;

    while (i <= j) {
        while (i<=high&&arr[i]<=p) {
            i++;
        }
        while (j>=low&&arr[j]>p) {
            j--;
        }
        if (i<j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
    }
    return j;
}
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}