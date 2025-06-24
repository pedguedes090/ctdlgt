#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int rows;
    int cols;
    int k;
    int sum=0;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));

    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("nhap so hang can tinh tong");
    scanf("%d",&k);
    if (0<k&&k<=rows) {
        for (int i = 0; i < rows; i++) {
            sum+=arr[k-1][i];
        }
        printf("so hang can tinh tong %d", sum);
    }
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}