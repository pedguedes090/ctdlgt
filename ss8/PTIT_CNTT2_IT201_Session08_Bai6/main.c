#include <stdio.h>
#include <stdlib.h>

int merge(int arr[],int left,int mid,int right) {
    int n1=mid -left+1;
    int n2=right - mid;
    int *L=(int *)malloc(n1*sizeof(int));
    int *R=(int *)malloc(n2*sizeof(int));
    for (int i=0;i<n1;i++) {
        L[i]=arr[left+i];
    }
    for (int i=0;i<n2;i++) {
        R[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=left;
    for (;i<n1&&j<n2;) {
        if (L[i]<=R[j]) {
            arr[k++]=L[i++];
        }else {
            arr[k++]=R[j++];
        }
    }
    for (;i<n1;i++) {
        arr[k++]=L[i++];
    }
    for (;j<n2;j++) {
        arr[k++]=R[j++];
    }
    free(L);
    free(R);
}
int merge_sort(int arr[],int left,int right) {
    if (left<right) {
        int mid = left+(right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
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
    merge_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
