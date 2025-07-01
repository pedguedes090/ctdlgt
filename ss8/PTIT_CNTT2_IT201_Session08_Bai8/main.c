#include <stdio.h>
#include <stdlib.h>
int linearSearch(int arr[],int n,int key) {
    for(int i=0;i<n;i++) {
        if(arr[i]==key) {
            return i+1;
        }
    }
}
int insertionSort(int arr[],int n) {
    for(int i=1;i<n;i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
    }
}
int binarySearch(int arr[],int n,int key) {
    insertionSort(arr,n);
    int low=0;
    int high=n-1;
    while(low<=high) {
        int mid=(low+high)/2;
        if(arr[mid]==key) {
            return mid+1;
        }else if(arr[mid]>key) {
            high=mid-1;
        }else {
            low=mid+1;
        }
    }
}
int main(void) {
    int n;
    printf("Please enter a number: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int a=0;
    do {
        printf("\n 1.tim kiem tuy tinh \n 2.tim kiem tuyen tinh (tu dong sap xep lai mang)\n");
        scanf("%d", &a);
        int key;
        printf("vui long nhap so can tim kiem ");
        scanf("%d", &key);
        switch (a) {
            case 1:
                printf("%d",linearSearch(arr, n, key));
                break;
            case 2:
                printf("%d", binarySearch(arr, n, key));
                break;
            case 0:
                exit(0);
            default:
                printf("vui long nhap lai");
                break;

        }
    }while(a>0&&a<=2);
    return 0;
}
