#include <ctype.h>
#include <stdio.h>
#include <string.h>
int convertStringToNumber(char *str,int n,int result) {
    if (str[n]=='\0') {
        return result;
    }
    if (!isdigit(str[n])) {
        return 0;
    }
    int number =str[n]-'0';

    return convertStringToNumber(str,n+1,result*10+number);
}
int main(void) {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strlen(str)-1]='\0';
    if (!convertStringToNumber(str,0,0)) {
        printf("Number is invalid\n");
    }
    else {
        printf("\n %d",convertStringToNumber(str,0,0));
    }
    return 0;
}