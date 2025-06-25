#include <stdio.h>
#include <string.h>

struct info {
    int id;
    char name[20];
    int age;
};
typedef struct info info;
int main(void) {
    int n;
    printf("vui long nhap so luong ohan tu");
    scanf("%d", &n);
    getchar();
    info arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].id=i+1;
        printf("vui long nhap ten");
        fgets(arr[i].name, 20, stdin);
        arr[i].name[strlen(arr[i].name) - 1] = '\0';
        printf("vui long nhap tuoi");
        scanf("%d", &arr[i].age);
        getchar();
    }
    int number;
    printf("vui long nhap so can tim");
    scanf("%d", &number);
    for (int i = 0; i < n; i++) {
        if (arr[i].id==number) {
            printf("%d\n %s\n %d\n", arr[i].id, arr[i].name, arr[i].age);
        }
    }
    return 0;
}