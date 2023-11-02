#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *head;

void create_node()
{
    NODE *temp;
    int n, i;
    head = (NODE *)malloc(sizeof(NODE));
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter Node 1: ");
    scanf("%d", &head->data);
    temp = head;
    for (i = 1; i < n; i++)
    {
        temp->next = (NODE *)malloc(sizeof(NODE));
        temp = temp->next;
        printf("Enter Node %d: ", i + 1);
        scanf("%d", &temp->data);
    }
    temp->next = NULL;
}

void display_list()
{
    NODE *temp;
    int nonZeroCount = 0, oddCount = 0, evenCount = 0;
    printf("Orignal List ");
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
        if (temp->data != 0)
            nonZeroCount++;

        if (temp->data % 2)
            oddCount++;
        else
            evenCount++;
    }
    printf("\nNon-zero Count : %d", nonZeroCount);
    printf("\nOdd Count : %d", oddCount);
    printf("\nEven Count : %d", evenCount);
}

int main()
{
    create_node();
    display_list();
}