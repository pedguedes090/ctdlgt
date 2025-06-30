#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int row;
    int col;
    printf("lui long nhap so dong va so cot");
    scanf("%d %d", &row, &col);
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int *)malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int k;
    printf("lui long nhap cot can sap xep");
    scanf("%d", &k);
    k--;
    for (int i = 0; i < row-1; i++) {
        for (int j=i+1; j<row; j++) {
            if (matrix[i][k]>matrix[j][k]) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[j][k];
                matrix[j][k] = temp;
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
