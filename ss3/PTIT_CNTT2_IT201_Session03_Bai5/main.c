#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int row;
    int col;
    do {
        printf("vui long nhap so hang");
        scanf("%d", &row);
        printf("vui long nhap so co cot");
        scanf("%d", &col);
    }while (row <= 0 || row <=0|| col <= 0 || col <= 0);
    int **arr= (int **) malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        arr[i] = (int *) malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int maindiagonal=0;
    int secondarydiagonal=0;
    for (int i = 0; i < row; i++) {
        maindiagonal+=arr[i][i];
    }
    for (int i = 0; i < row; i++) {

            secondarydiagonal =secondarydiagonal + arr[i][row-1-i];


    }
    printf("duong cheo chinh = %d\n", maindiagonal);
    printf("duong cheo phu =%d", secondarydiagonal);
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
