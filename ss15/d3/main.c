#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    char author[100];
    char category[100];
    float price;
}Book;
typedef struct SNode {
    Book data;
    struct SNode *next;
}SNode;
typedef struct DNode {
    Book data;
    struct DNode *next;
    struct DNode *prev;
} DNode;
SNode* booklist = NULL;
DNode* readList =NULL;
SNode* createNOde(Book data) {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = NULL;
};
DNode* createDNode(Book data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
};
void addBook() {
    Book b;
    printf("Vui long nhap id book");
    scanf("%d",&b.id);
    getchar();
    printf("Vui long nhap title book");
    fgets(b.title,100,stdin);
    b.title[strlen(b.title)-1] = '\0';
    printf("Vui long nhap author book");
    fgets(b.author,100,stdin);
    b.author[strlen(b.author)-1] = '\0';
    printf("Vui long nhap category book");
    fgets(b.category,100,stdin);
    b.category[strlen(b.category)-1] = '\0';
    printf("Vui long nhap price book");
    scanf("%f",&b.price);
    getchar();
    SNode* newNode = createNOde(b);
    newNode->next = booklist;
    booklist = newNode;
    printf("da them book thanh cong");
};
void printBookList() {
    SNode* temp = booklist;
    if (temp == NULL) {
        return;
    }
    while (temp) {
        Book b = temp->data;
        printf("ID :%d\t Title :%s\t Author : %s\t Category :%s\t Price :%.2f\n", b.id, b.title, b.author, b.category, b.price);

        temp = temp->next;
    }
}
void deleteBook(int id) {
    SNode* temp = booklist;
    SNode* Prev;
    if (temp == NULL) {
        return;
    }
    while (temp && temp->data.id != id) {
        Prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    if (!Prev) {
        booklist = temp->next;
    }else {
        Prev->next = temp->next;
    }
    free(temp);
    printf("da xoa thanh cong Book %d",id);
}
void updateBook(int id) {
    SNode* temp = booklist;
    if (temp == NULL) {
        return;
    }
    while (temp && temp->data.id != id) {
        temp = temp->next;
    }
    Book* b = &temp->data;
    printf("Vui long nhap Title book");
    fgets(b->title,100,stdin);
    b->title[strlen(b->title)-1] = '\0';
    printf("Vui long nhap author book");
    fgets(b->author,100,stdin);
    b->author[strlen(b->author)-1] = '\0';
    printf("Vui long nhap category book");
    fgets(b->category,100,stdin);
    b->category[strlen(b->category)-1] = '\0';
    printf("Vui long nhap price book");
    scanf("%f",&b->price);
    getchar();
}
void readBookList(int id) {
    SNode* temp = booklist;
    SNode* Prev = NULL;
    if (temp == NULL) {
        return;
    }
    while (temp && temp->data.id != id) {
        Prev = temp;
        temp = temp->next;
    }
    Book b = temp->data;
    if (!Prev) {
        booklist = temp->next;
    };
    DNode* newNode = createDNode(b);
    newNode->next = readList;
    if (readList == NULL) {
        readList->prev = newNode;
    }
    readList = newNode;
    printf("Da doc thanh cong Book %d",id);
}
void sortBookList() {
    if (!booklist&& !booklist->next) {
        return;
    }
    for (SNode* i = booklist; i; i = i->next) {
        for (SNode* j = i->next; j; j = j->next) {
            if (i->data.id > j->data.id) {
                Book temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("da sap xep thanh cong");
}
void findBook(char* title) {
    SNode* temp = booklist;
    if (temp == NULL) {
        return;
    }
    int flag = 0;
    while (temp) {
        if (strstr(temp->data.title,title)) {
            Book b = temp->data;
            printf("ID :%d\t Title :%s\t Author : %s\t Category :%s\t Price :%.2f\n", b.id, b.title, b.author, b.category, b.price);
            flag = 1;
        }
        temp = temp->next;
    }
    if (!flag) {
        printf("Khong tim thay ");
        return;
    }


}
void menu(){
    printf("\n MENU \n");
    printf("1.Add Book \n");
    printf("2.Delete Book \n");
    printf("3.Print Book \n");
    printf("4.Update Book \n");
    printf("5.Read Book \n");
    printf("6.Sort Book \n");
    printf("7.Find Book \n");
    printf("8.Exit\n");
    printf("\n Enter your choice : ");
};

int main(void){
    int choice = 0;
    int id;
    char title[100];
    do {
        menu();
        scanf("%d",&choice);
        getchar();
        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                printf("Vui long nhap ID");
                scanf("%d",&id);
                deleteBook(id);
                break;
            case 3:
                printBookList();
                break;
            case 4:
                printf("Vui long nhap ID");
                scanf("%d",&id);
                getchar();
                updateBook(id);
                break;
            case 5:
                printf("Vui long nhap ID");
                scanf("%d",&id);
                getchar();
                readBookList(id);
                break;
            case 6:
                sortBookList();
                break;
            case 7:
                printf("Vui long nhap Title");
                fgets(title,100,stdin);
                title[strlen(title)-1] = '\0';
                findBook(title);
                break;
            case 8:
                exit(0);
            default:
                printf("Vui long nhap lai");
                break;

        }
    }while(choice!=8);
    return 0;
};