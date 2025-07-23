#include <stdio.h>
#define MAX 3

void initGraph(int graph[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }
}
void addEdge(int graph[MAX][MAX], int node1, int node2) {
    if (node1<0 || node2<0 || node1 > MAX || node2 > MAX) {
        printf("Vi tri cua node khong hop le\n");
        return;
    }
    graph[node1][node2]=1;
}
void displayGraph(int graph[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int graph[MAX][MAX];
    initGraph(graph);
    int node1, node2;
    printf("Nhap nut khoi dau canh: ");
    scanf("%d", &node1);
    printf("Nhap nut ket thuc canh: ");
    scanf("%d", &node2);
    addEdge(graph, node1, node2);
    displayGraph(graph);
    return 0;
}