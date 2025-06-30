#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int l, int m, int r) {
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++) {
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++) {
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    for (k=l;i<n1&&j<n2;k++) {
        if (L[i]<=R[j]) {
            arr[k]=L[i++];
        }else {
            arr[k]=R[j++];
        }
    }
    for (;i<n1;i++) {
        arr[k]=L[i];
    }
    for (;j<n2;j++) {
        arr[k]=R[j];
    }
}
int mergeSort(int arr[], int l, int r) {
    if (l<r) {
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
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
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
