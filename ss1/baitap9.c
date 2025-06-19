//
// Created by dun on 6/16/2025.
//
#include <stdio.h>
int printMatrix(int a,int b,int arr[a][b]) {
    for (int i =0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}//độ phức tạp thời gian là O(n), độ phức tạp thời gian là O(1)
int printmaindiagonal(int a,int b,int arr[a][b]) {
    if (a==b) {
        for (int i =0; i < a; i++) {
            printf("%d ",arr[i][i]);
        }
    }else {
        return 0;
    }

}//độ phức tạp không gian là O(n),độ phức tạp thời gian là O(1)
int main() {
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    printMatrix(3,3,arr);
    printmaindiagonal(3,3,arr);

}