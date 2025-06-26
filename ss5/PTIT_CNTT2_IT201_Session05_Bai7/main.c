#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int arr[],int n,int nmax) {
    if (n==0) {
        if (n<nmax) {
            arr[0] = 0;
        }
        return 0;
    }
    if (n==1) {
        if (n<nmax) {
            arr[1] = 1;
        }
        return 1;
    }
    if (n<nmax&&arr[n]!=0) {
        return arr[n];
    }
    int result = fibonacci(arr,n-1,nmax)+fibonacci(arr,n-2,nmax);
    if (n<nmax) {
        arr[n] = result;
    }
    return result;
}
int main(void) {
    int n;
    scanf("%d",&n);
    int *arr = calloc(n,sizeof(int));
    fibonacci(arr,n-1,n);
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}