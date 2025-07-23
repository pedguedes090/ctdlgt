#include <stdio.h>
#define MAX 4

void initGraph(int graph[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[MAX][MAX], int node1, int node2) {
    if (node1<0 || node2<0 || node1 > MAX || node2 > MAX) {
        printf("vi tri node khong ton tai\n");
        return;
    }
    graph[node1][node2]=1;
    graph[node2][node1]=1;
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
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    displayGraph(graph);
    return 0;
}