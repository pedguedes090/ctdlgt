//
// Created by dun on 6/16/2025.
//
#include <stdio.h>
int main() {
    int arr[]={1,76,3,3,5,6,1,3,9,43};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxcount=0;
    int maxitem =0;
    for (int i =0; i < n; i++ ) {
        int count =0;
        for (int j =i+1; j < n; j++ ) {
            if (arr[i] == arr[j]) {
                count++;
            }
            if (count > maxcount) {
                maxcount = count;
                maxitem = arr[i];
            }
        }
    }
    // đj phức tạp thời gian là 0(n2) ,độ phức tạp không gian là 0(1)
    printf("%d",maxitem);
}
