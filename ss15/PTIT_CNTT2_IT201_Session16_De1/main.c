#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Course {
    int id;
    char title[100];
    int credits;
} Course;
typedef struct SNode {
    Course data;
    struct SNode *next;
}SNode;
typedef struct DNode {
    Course data;
    struct DNode *next;
    struct DNode *prev;
}DNode;
SNode* head = NULL;
DNode* completeCourseHead = NULL;

int checkid(int id) {
    SNode* temp = head;
    while (temp) {
        if (temp->data.id == id) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
//ham them khoa hoc
void addCourse() {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    if (newNode ==NULL) {
        printf("cap nhat bo nho khong thanh cong");
        return;
    }
    do {
        printf("Moi ban nhap ID");
        scanf("%d",&newNode->data.id);
        getchar();
        if (checkid(newNode->data.id)) {
            printf("id da ton tai vui long nhap lai \n");
        }
    }while (checkid(newNode->data.id));
    printf("Moi ban nhap Ten khoa hoc");
    fgets(newNode->data.title,100,stdin);
    newNode->data.title[strlen(newNode->data.title)-1] = '\0';
    printf("Moi ban nhap so tin chi");
    scanf("%d",&newNode->data.credits);
    getchar();
    newNode->next =head;
    head = newNode;
    printf("Da them khoa hoc thanh cong");
}

//hien thi danh sach dang hoc
void displayCourse() {
    if (!head) {
        printf("danh sach khoa hoc dang rong \n");
        return;
    }
    SNode* temp = head;
    printf("danh sach khoa hoc dang hoc \n");
    while (temp) {
        printf("ID:%d | ten %s | Tin chi: %d \n",temp->data.id,temp->data.title,temp->data.credits);
        temp = temp->next;
    }
}
void deleteCourse() {
    int id;
    printf("vui long nhap ID khoa hoc ma ban muon xoa");
    scanf("%d",&id);
    SNode* temp =head;
    SNode* prev =NULL;
    while (temp && temp->data.id !=id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("khong tim thay khoa hoc");
        return;
    }
    if (!prev) {
        head = temp->next;
    }else {
        prev->next = temp->next;
    }
    free(temp);
    printf("da xoa thanh cong");
}

void updateCourse() {
    int id;
    printf("Vui long nhap ID khoa hoc");
    scanf("%d",&id);
    SNode* temp = head;
    while (temp && temp->data.id !=id) {
        temp = temp->next;
    }
    if (!temp) {
        printf("khong tim thay khoa hoc\n");
        return;
    }
    getchar();
    printf("Vui long nhap ten khoa hoc moi\n");
    fgets(temp->data.title,100,stdin);
    temp->data.title[strlen(temp->data.title)-1] = '\0';
    printf("vui long nhap  tin chi moi");
    scanf("%d",&temp->data.credits);
    printf("cap nhap khoa hoc thanh cong");
}
void completeCourse() {
    int id ;
    printf("vui long nhap ID khoa hoc");
    scanf("%d",&id);
    SNode* temp = head;
    SNode* prev =NULL;
    while (temp && temp->data.id !=id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("khong tim thay khoa hoc\n");
        return;
    }
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = temp->data;
    newNode->prev = NULL;
    newNode->next = completeCourseHead->prev=newNode;
    if (completeCourseHead) {
        completeCourseHead->prev = newNode;
    }
    completeCourseHead = newNode;

    if (!prev) {
        head = temp->next;
    }else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Da thanh cong");
}
void sortCourse() {
    if (!head||!head->next) {
        return;
    }
    SNode *i;
    SNode *j;
    for (i=head;i && i->next;i=i->next) {
        for (j=i->next;j;j=j->next) {
            if (i->data.credits > j->data.credits) {
                Course temp =i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Da xap xep thanh cong");
}
void searchCourse() {
    char key[100];
    printf("vui long nhap ten khoa hoc can tim kiem \n");
    fgets(key,100,stdin);
    key[strlen(key)-1] = '\0';
    SNode* temp = head;
    int flag = 0;
    while (temp) {
        if (strstr(temp->data.title,key)) {
            printf("ID:%d | ten %s | Tin chi: %d \n",temp->data.id,temp->data.title,temp->data.credits);
            flag = 1;
        }
        temp = temp->next;
    }
    if (!flag) {
        printf("khong tim thay khoa hoc");
    }
}
void freeAll() {
    SNode* temp;
    while (head) {
        temp =head;
        head = head->next;
        free(temp);
    }
    DNode*dtemp;
    while (dtemp) {
        dtemp= completeCourseHead;
        completeCourseHead = completeCourseHead->next;
        free(dtemp);
    }
}
int main(void) {
    int choice;
    do {
        printf("danh sach quan li\n");
        printf("1. add course\n");
        printf("2. display course\n");
        printf("3. delete course\n");
        printf("4. update course\n");
        printf("5. complete Course \n");
        printf("6. sort course\n");
        printf("7. search course\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                addCourse();
                break;
            case 2:
                displayCourse();
                break;
            case 3:
                deleteCourse();
                break;
            case 4:
                updateCourse();
            case 5:
                completeCourse();
            case 6:
                sortCourse();
            case 7:
                searchCourse();
            case 8:
                freeAll();
                break;
        }
    }while (choice !=8);
    return 0;
}