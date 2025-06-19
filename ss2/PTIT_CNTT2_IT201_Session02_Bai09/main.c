#include <stdio.h>

int main(void) {
    int n;
    int arr[100];
    int maxcount;
    int maxitem;
    do {
        printf("nhap so phan tu cua mang (0 < n <= 100) ");
        scanf("%d", &n);
    }while(n < 1 || n > 100);
    for (int i =0;i<n;i++) {
        scanf("%d", &arr[i]);
    };
    for (int i =0;i<n;i++) {
        int count = 0;
        for (int j =0;j<n;j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxcount) {
            maxcount = count;
            maxitem = arr[i];
        }
    }
    printf("max item = %d\n", maxitem);

    return 0;
}