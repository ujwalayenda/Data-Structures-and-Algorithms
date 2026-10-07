//A transportation network contains cities connected by roads with different costs. Write a C
program implementing Dijkstra’s Shortest Path Algorithm that accepts the number of vertices,
weighted adjacency matrix and source vertex, computes the minimum distance from the source to
every other vertex, and displays each destination with its shortest distance. Test it using at least
five vertices.//

#include <stdio.h>
#define MAX 100
#define INF 99999
void dijkstra(int graph[MAX][MAX], int n, int source) {
    int distance[MAX];
    int visited[MAX];
    int i, j, min, nextVertex;
    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }
    distance[source] = 0;
    visited[source] = 1;
    // Find shortest paths
    for (i = 1; i < n; i++) {
        min = INF;
        nextVertex = -1;
        // Find the unvisited vertex with minimum distance
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                nextVertex = j;
            }
        }
        // If no reachable vertex remains
        if (nextVertex == -1) {
            break;
        }
        visited[nextVertex] = 1;
        // Update distances of adjacent vertices
        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                graph[nextVertex][j] != INF &&
                distance[nextVertex] + graph[nextVertex][j] < distance[j]) {

                distance[j] = distance[nextVertex] + graph[nextVertex][j];
            }
        }
    }
    // Display shortest distances
    printf("\nShortest distances from source vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        if (distance[i] == INF) {
            printf("Vertex %d -> Not reachable\n", i);
        } else {
            printf("Vertex %d -> %d\n", i, distance[i]);
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int n, source;
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weighted adjacency matrix:\n");
    printf("(Enter %d for no direct connection)\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);
    dijkstra(graph, n, source);
    return 0;
}

//nput:

5
0 10 3 99999 99999
10 0 1 2 99999
3 1 0 8 2
99999 2 8 0 4
99999 99999 2 4 0
0
Output:

Enter the number of vertices: 5
Enter the weighted adjacency matrix:
(Enter 99999 for no direct connection)
Enter the source vertex (0 to 4): 0

Shortest distances from source vertex 0:
Vertex 0 -> 0
Vertex 1 -> 4
Vertex 2 -> 3
Vertex 3 -> 6
Vertex 4 -> 5//
