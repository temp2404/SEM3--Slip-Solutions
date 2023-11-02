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
    for (i = 2; i <= n; i++)
    {
        temp->next = (NODE *)malloc(sizeof(NODE));
        temp = temp->next;
        printf("Enter Node %d: ", i);
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
    printf("\n");
}

int main()
{
    int opt;
    do
    {
        printf("\n\nMenu:\n1 : Create\n2 : Display\n3 : Exit");
        printf("\nEnter Choice : ");
        scanf("%d", &opt);
        printf("\n");
        switch (opt)
        {
        case 1:
            create_node();
            break;
        case 2:
            display_list();
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("Invalid Option");
        }
    } while (opt != 3);

    return 0;
}