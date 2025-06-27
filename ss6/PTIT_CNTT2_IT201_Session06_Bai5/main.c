#include <stdio.h>
#include <stdlib.h>

int min(int n,int *arr) {
    if (n==0) {
        return -1;
    }
    if (n==1) {
        return arr[0];
    }
    if (arr[n-1]<min(n-1,arr)) {
        return arr[n-1];
    }
    return min(n-1,arr);

}
int max(int n,int *arr) {
    if (n==0) {
        return -1;
    }
    if (arr[n-1]>max(n-1,arr)) {
        return arr[n-1];
    }
    return max(n-1,arr);
}
int minMax(int n,int *arr) {
    int minValue = min(n,arr);
    int maxValue = max(n,arr);
    printf("min = %d, max = %d\n", minValue, maxValue);

}
int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    minMax(n,arr);
    return 0;
}