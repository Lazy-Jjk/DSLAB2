#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int adj[MAX_VERTICES][MAX_VERTICES], visited[MAX_VERTICES];

void bfs(int vertex, int n) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = vertex;
    visited[vertex] = 1;
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, e;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(start, n);

    return 0;
}
