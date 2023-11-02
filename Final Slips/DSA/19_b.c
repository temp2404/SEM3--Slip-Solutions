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

void display_alternative()
{
    NODE *temp;
    int i;
    for (i = 1, temp = head; temp != NULL; i++, temp = temp->next)
    {
        if (i % 2 == 1)
            printf("%d ", temp->data);
    }
}

int main()
{
    create_node();
    printf("Orignal List: ");
    display_list();
    printf("\nAlternative Node Display: ");
    display_alternative();

    return 0;
}