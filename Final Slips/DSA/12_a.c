#include <stdio.h>

#define MAX_VERTICES 100

int isUndirected(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = i + 1; j < vertices; j++)
        {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i])
            {
                return 0; // Not symmetric, so not undirected
            }
        }
    }
    return 1; // Symmetric, so undirected
}

void calculateInDegrees(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertices, int inDegrees[MAX_VERTICES])
{
    for (int i = 0; i < vertices; i++)
    {
        inDegrees[i] = 0;
        for (int j = 0; j < vertices; j++)
        {
            inDegrees[i] += adjacencyMatrix[j][i];
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

    if (isUndirected(adjacencyMatrix, vertices))
    {
        printf("The graph is undirected (the adjacency matrix is symmetric).\n");
    }
    else
    {
        printf("The graph is not undirected (the adjacency matrix is not symmetric).\n");
    }

    int inDegrees[MAX_VERTICES];
    calculateInDegrees(adjacencyMatrix, vertices, inDegrees);

    printf("In-degrees of vertices:\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("Vertex %d: %d\n", i, inDegrees[i]);
    }

    return 0;
}
