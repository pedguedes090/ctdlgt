#include <stdio.h>

int towerHaNoi(int n ,char a,char b,char c) {
    if (n==0) {
        return 0;
    }

    towerHaNoi(n-1,a,c,b);
    printf("da di chuyen dia tu %c sang %c \n",a,c);
    towerHaNoi(n-1,b,a,c);
}
int main(void) {
    int n;
    printf("Please enter a number: ");
    scanf("%d", &n);
    towerHaNoi(n,'a','b','c');
    return 0;
}