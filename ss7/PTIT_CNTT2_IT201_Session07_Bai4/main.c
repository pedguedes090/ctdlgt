#include <stdio.h>
#include <string.h>

int sort(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            int temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
}

int main(void) {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    sort(str);
    printf("Sorted string: %s\n", str);
    return 0;
}
