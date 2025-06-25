#include <stdio.h>
#include <stdlib.h>

int searchNumber(int arr[],int left,int right,int num) {
    int mid = left+(right-left)/2;
    if (arr[mid]==num) {
        return mid;
    }
    if (arr[mid]<num) {
        return searchNumber(arr,left,mid-1,num);
    }
    if (arr[mid]>num) {
        return searchNumber(arr,mid+1,right,num);
    }
}
int main(void) {
    int n;
    printf("vui long nhap so phan tu cua mang");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]>arr[j]) {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int num;
    printf("vui long nhap so can tim kiem ");
    scanf("%d",&num);
    int left =0;
    int right =n-1;
    if (searchNumber(arr,left,right,num)) {
        printf("co phan tu trong mang");
    }else {
        printf("khong co phan tu trong mang");
    }
    free(arr);
    return 0;
}