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
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
}

void search()
{
    NODE *temp;
    int flag = 0, i, sd;
    printf("\nEnter Node Data to Search: ");
    scanf("%d", &sd);
    for (temp = head, i = 0; temp != NULL; temp = temp->next, i++)
    {
        if (temp->data == sd)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        printf("\n%d Found at position %d", sd, i);
    else
        printf("\nNumber not Found");
}

int main()
{
    create_node();
    printf("List: ");
    display_list();
}