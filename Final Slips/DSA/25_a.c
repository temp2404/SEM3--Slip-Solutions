#include <stdio.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES];

void DFS(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex)
{
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    for (int i = 0; i < vertices; i++)
    {
        if (adjacencyMatrix[startVertex][i] && !visited[i])
        {
            DFS(adjacencyMatrix, vertices, i);
        }
    }
}

int main()
{
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= vertices)
    {
        printf("Invalid starting vertex. It should be between 0 and %d.\n", vertices - 1);
        return 1;
    }

    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    printf("Depth-First Search starting from vertex %d: ", startVertex);
    DFS(adjacencyMatrix, vertices, startVertex);
    printf("\n");

    return 0;
}
