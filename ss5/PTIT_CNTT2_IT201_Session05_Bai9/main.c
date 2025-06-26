#include <stdio.h>

int countpatch(int i,int j,int row,int col) {
    if(i==row-1 && j==col-1) {
        return 1;

    }
    if (i>=row || j>=col) {
        return 0;
    }
    return countpatch(i+1,j,row,col)+countpatch(i,j+1,row,col);
}
int main(void) {
    int row,col;
    scanf("%d %d",&row,&col);
    int tutal=countpatch(0,0,row,col);
    printf("%d",tutal);
    return 0;
}