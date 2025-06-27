#include <stdio.h>
#include <string.h>

int sumNumber(number) {
    if (number == 0) {
        return 0;
    }
    return number%10 + sumNumber(number/10);
}

int main(void) {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("The sum of the digits of the number is: %d\n", sumNumber(number));
    return 0;
}