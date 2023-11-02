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

void reverse()
{
    NODE *s, *temp;
    int count = 0, i;
    for (s = head; s != NULL; s = s->next)
        count++;
    while (count != 0)
    {
        temp = head;
        for (i = 1; i <= count - 1; i++)
        {
            temp = temp->next;
        }
        printf("%d ", temp->data);
        count--;
    }
}

int main()
{
    create_node();
    printf("Orignal List: ");
    display_list();
    printf("\nReverse List: ");
    reverse();
    return 0;
}