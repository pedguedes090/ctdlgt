//
// Created by dun on 6/16/2025.
//
#include <stdio.h>
int main() {
    int arr[]={1,2,3,4,5,6,7,8,9};
    int sum=0;
    for (int i=0;i< sizeof(arr)/sizeof(arr[0]);i++ ) {
        sum+=arr[i];
    }
    printf("%d",sum);
}

// độ phức tạp thời gian của thuật toán là o(n)