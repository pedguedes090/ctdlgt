#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n;
    int max=0;
    do {
        printf("vui long nhap so: ");
        scanf("%d ",&n);
        if (n<0) {
            printf("vui long nhap so luong phan tu khong duoc am");
        }else if (n==0) {
            printf("so luong phan tu phai lon hon 0");
        }
    }while(n<=0);
    int *arr =(int *)calloc(n,sizeof(int));
    if (arr==NULL) {
        printf("khong the cap phat bo nho ");
    }
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    };
    for (int i=0;i<n;i++) {
        if (arr[i]>max) {
            max=arr[i];
        }
    }
    printf("%d",max);
    return 0;
}