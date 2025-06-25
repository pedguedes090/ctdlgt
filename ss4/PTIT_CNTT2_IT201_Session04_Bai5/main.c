#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("vui long hap phan tu ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int number;
    printf("vui long nhap phan tu ");
    scanf("%d", &number);
    int l=0;
    int r=n-1;
    while (l<=r) {
        int m = (l+r)/2;
        if (number==arr[m]) {
            printf("phan tu co trong mang");
            return 0;
        }
        if (number>arr[m]) {
            l=m+1;

        }else {
            r=m-1;
        }
    }
    return 0;
}
