#include <stdio.h>
#include <string.h>

int checkPalindrome(char arr[],int left,int right) {
    if (left >= right) {
        printf("Palindrome valid");
        return 1;
    }
    if (arr[left] != arr[right]) {
        printf("Palindrome invalid");
        return 0;
    }
    return checkPalindrome(arr,left+1,right-1);
}
int main(void) {
    char str[100];
    printf("vui long nhap 1 chuoi ki tu");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
    checkPalindrome(str, 0, strlen(str) - 1);

    return 0;
}
