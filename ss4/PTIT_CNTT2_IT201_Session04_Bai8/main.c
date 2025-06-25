#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 0; i < n; i++) {
        if (number == arr[i]) {
            printf("%d",i);
        }
    }
    return 0;
}
