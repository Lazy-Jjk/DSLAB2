#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int adj[MAX_VERTICES][MAX_VERTICES], visited[MAX_VERTICES];

void bfsRecursive(int queue[], int front, int rear, int n) {
    if (front == rear) return; // Base case: stop if queue is empty

    int vertex = queue[front];
    front++; // Move the front of the queue

    printf("%d ", vertex);  // Visit the current node

    // Enqueue all unvisited neighbors
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            visited[i] = 1;
            queue[rear++] = i;
        }
    }

    bfsRecursive(queue, front, rear, n); // Recursive call to process the next level
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
        adj[u][v] = adj[v][u] = 1; // Undirected graph
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    visited[start] = 1;  // Mark the starting vertex as visited
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = start;  // Add the starting vertex to the queue

    printf("BFS traversal: ");
    bfsRecursive(queue, front, rear, n);

    return 0;
}
