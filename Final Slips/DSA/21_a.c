#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Queue
{
    int items[MAX_VERTICES];
    int front, rear;
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

void enqueue(struct Queue *queue, int value)
{
    if (queue->rear == MAX_VERTICES - 1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(struct Queue *queue)
{
    int item;
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        item = -1;
    }
    else
    {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
        {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

void BFS(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex)
{
    int visited[MAX_VERTICES];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    struct Queue *queue = createQueue();

    printf("Breadth-First Search starting from vertex %d: ", startVertex);
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    enqueue(queue, startVertex);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);

        for (int i = 0; i < vertices; i++)
        {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
            {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
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
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= vertices)
    {
        printf("Invalid starting vertex. It should be between 0 and %d.\n", vertices - 1);
        return 1;
    }

    BFS(adjacencyMatrix, vertices, startVertex);

    return 0;
}
