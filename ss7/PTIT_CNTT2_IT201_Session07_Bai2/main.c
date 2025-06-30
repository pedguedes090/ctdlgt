#include <stdio.h>
#include <stdlib.h>

int selection(int arr[],int n) {
    for(int i=0;i<n;i++) {
         int min =i;
        for (int j=i+1;j<n;j++) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    selection(arr,n);
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}