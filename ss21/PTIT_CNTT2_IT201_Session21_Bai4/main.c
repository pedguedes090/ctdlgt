#include <stdio.h>
#define MAX 3
void initGrraph(int graph[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }
}
void addEdge(int graph[MAX][MAX], int node1, int node2) {
    if (node1<0 || node2<0 || node1 >= MAX || node2 >= MAX) {
        printf("Vi tri node khong hop le\n");
        return;
    }
    graph[node1][node2]=1;
}
void displayGrraph(int graph[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int graph[MAX][MAX];
    initGrraph(graph);
    addEdge(graph,1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    displayGrraph(graph);
    return 0;
}