#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int m;
    printf("n = ");
    scanf("%d ", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("m = ");
    scanf("%d", &m);
    arr=(int *)realloc(arr,n+m);
    for (int i = n; i < n+m; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n+m; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
