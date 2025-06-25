#include <stdio.h>
#include <strings.h>
struct info {
    int id;
    char name[20];
    int age;
};
typedef struct info info;
int main(void) {
    int n;
    printf("vui long nhap so phan tu");
    scanf("%d", &n);
    getchar();
    info arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].id = i+1;
        fgets(arr[i].name, 20, stdin);
        arr[i].name[strlen(arr[i].name) - 1] = '\0';
        scanf("%d", &arr[i].age);
        getchar();
    }
    char str2[100];
    printf("vui long nhap chu can tim kiem");
    fgets(str2, 100, stdin);
    str2[strlen(str2) - 1] = '\0';
    for (int i = 0; i < n; i++) {
        if (strstr(arr[i].name,str2)){
           printf("%s %d %d\n", arr[i].name, arr[i].age, arr[i].id);

        }
    }

    return 0;
}