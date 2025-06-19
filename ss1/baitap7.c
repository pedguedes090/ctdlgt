//
// Created by dun on 6/16/2025.
//
#include <stdio.h>
int c1(int arr[],int n) {
    for (int i =0; i < n; i++ ) {
        for (int j =i+1; j < n; j++ ) {
            if (arr[i] == arr[j]) {
                printf("so %d trung lap ",arr[i]);
                return arr[i];
            }
        }
    }
}
// độ phức tạp thời gian O(n2) , độ phức tạp không gian O(1)
int sort(int arr[], int n) {
    for (int i =0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;

}
int c2(int arr[],int n) {
    sort(arr,n);
    for (int i =0; i < n; i++) {
        if (arr[i] == arr[i+1]) {
            printf("so %d trung lap",arr[i]);

        }
    }
    return 0;
}
// độ phức tạp thời gian O(n) , độ phức tạp không gian O(1)
int main() {
    int arr[]={1,12,34,4,52,6,9,18,9};
    int n =sizeof(arr)/sizeof(arr[0]);
    c1(arr,n);
    c2(arr,n);
}