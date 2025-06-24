#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int row=3;//hang
    int col=3;//cot
    do {
        printf("vui long nhap so hang");
        scanf("%d",&row);
        printf("vui long nhap so hang");
        scanf("%d",&col);
    }while(row<=0 || col<=0);
    int **arr;
    arr = (int **)malloc(row *sizeof(int *));
    for(int i=0;i<row;i++) {
        arr[i]=(int *)malloc(col*sizeof(int));
    }
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            printf("%5d ",arr[i][j]);
        }
        printf("\n");
    }
    int max;
    int min;
    for(int i=0;i<row;i++) {
        for(int j=i;j<col;j++) {
            if(arr[i][j]>max) {
                max=arr[i][j];
            }
            if(arr[i][j]<min) {
                min=arr[i][j];
            }
        }
    }
    for(int i=0;i<row;i++) {
        free(arr[i]);
    }
    free(arr);
    printf("max=%d\n",max);
    printf("min=%d\n",min);
    return 0;
}