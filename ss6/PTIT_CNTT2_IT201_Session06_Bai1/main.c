#include <stdio.h>
#include <string.h>

int convertNumberToBinary(int number) {
    if (number == 0) {
        return 0;
    }
    convertNumberToBinary(number/2);
    printf("%d", number%2);
}


int main(void) {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    convertNumberToBinary(number);
    return 0;
}