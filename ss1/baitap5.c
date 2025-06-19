//
// Created by dun on 6/16/2025.
//
#include <stdio.h>
int main() {
    int arr[]={1,12,34,4,52,6,73,18,19};
    int temp =0;
    for (int i =0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        for (int j = i; j < sizeof(arr)/sizeof(arr[0]); j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }
    for (int i =0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        printf("%d ",arr[i]);
    }
}

// độ phức tạp của thuật toán là 0(n2)