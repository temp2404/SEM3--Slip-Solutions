#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} QUEUE;

QUEUE *front = NULL, *rare = NULL;

int isEmpty()
{
    if (front == NULL && rare == NULL)
        return 1;
    return 0;
}

void enqueue(int element)
{
    QUEUE *newnode;
    newnode = (QUEUE *)malloc(sizeof(QUEUE));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newnode->data = element;
    newnode->next = NULL;
    if (isEmpty())
        front = rare = newnode;
    else
    {
        rare->next = newnode;
        rare = newnode;
    }
}

int dequeue()
{
    if (isEmpty())
        exit(1);

    QUEUE *temp;
    temp = front;

    int data = temp->data;
    front = front->next;
    free(temp);

    if (front == NULL)
        rare = NULL;

    return data;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return;
    }
    QUEUE *temp;
    for (temp = front; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

int main()
{
    int n, ch;
    do
    {
        printf("\nMenu:\n1: Insert\n2: Delete\n3: Display\n4: Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Element to Insert: ");
            scanf("%d", &n);
            enqueue(n);
            printf("Queue Elements: ");
            display();
            break;
        case 2:
            if (!isEmpty())
            {
                printf("Deleted Element: %d\n", dequeue());
                printf("Queue Elements: ");
                display();
            }
            else
                printf("Queue is Empty. Cannot delete.\n");
            break;
        case 3:
            printf("Queue Elements: ");
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (ch != 4);

    return 0;
}