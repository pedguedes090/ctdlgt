#include <stdio.h>
#include <stdlib.h>
//
// Created by dun on 6/16/2025.
//
int * mallocArray(int n) {
    int* arr=(int*)malloc(n * sizeof(int));
    for (int i =0; i<n;i++) {
        arr[i]=i;
    }
    return arr;
}
int main() {
    int n =0;
    scanf("%d",&n);
    mallocArray(n);
}
// độ phức tạp không gian là o(n)