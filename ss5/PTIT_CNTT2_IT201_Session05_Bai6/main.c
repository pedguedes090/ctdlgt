#include <stdio.h>
#include <stdlib.h>

int sum(int arr[],int left,int right) {
    if (left > right) {
        return 0;
    }
    return arr[left]+sum(arr,left+1,right);

}
int main(void) {
    int n;
    printf("vui long nhao so luong phan tu");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("%d",sum(arr,0,n-1));
    return 0;
}