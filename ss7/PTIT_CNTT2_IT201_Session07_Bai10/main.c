#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int p;
    printf("vui long nhap khong cach");
    scanf("%d", &p);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int j1 =abs(arr[i]-p);
            int j2 =abs(arr[j]-p);
            if (j1>j2) {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;
}
