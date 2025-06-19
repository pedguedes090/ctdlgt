//
// Created by dun on 6/16/2025.
//
#include <stdio.h>
int main() {
    int arr[]={1,3,34,4,52,6,3,18,3};
    int n;
    int count=0;
    scanf("%d",&n);
    for (int i=0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        if (arr[i]==n) {
            count++;

        }
    }
    printf("%d",count);
}
//độ phức tạp về thời gian của thuật toán là O(n) , đôh phức tạp về khng gian là O(1)