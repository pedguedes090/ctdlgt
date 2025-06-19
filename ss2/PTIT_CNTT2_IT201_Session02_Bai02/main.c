#include <stdio.h>

int main(void) {
    int n;
    int arr[100];
    int count;
    int num;
    do {
        printf("nhap so phan tu cua mang (0 < n <= 100) ");
        scanf("%d", &n);
    }while(n < 1 || n > 100);
    for (int i =0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    printf("moi nhap so can tim");
    scanf("%d", &num);
    for (int i =0;i<n;i++) {
       if(arr[i] == num) {
           count++;
       }
    }
    printf("so lan xuat hien cua %d la", count);
    return 0;
}