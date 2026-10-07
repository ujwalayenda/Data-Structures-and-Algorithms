//A network of n locations is represented as a graph. Write a C program that accepts the graph
using an Adjacency Matrix, accepts a starting vertex, performs a graph traversal, displays the visit
order, and ensures that a vertex is not processed repeatedly. Test it with connected and partially
connected graphs.//

#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int n;
// BFS traversal
void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    int i, current;
    // Mark starting vertex as visited
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS Traversal: ");
    while (front < rear) {
        current = queue[front++];
        printf("%d ", current);
        // Check all adjacent vertices
        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
int main() {
    int start;
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    BFS(start);
    return 0;
}

//Input:
5
  
0 1 1 0 0
1 0 1 1 0
1 1 0 0 1
0 1 0 0 1
0 0 1 1 0

0
Output:
Enter the number of vertices: 5
Enter the adjacency matrix:
Enter the starting vertex (0 to 4): 0
BFS Traversal: 0 1 2 3 4//
