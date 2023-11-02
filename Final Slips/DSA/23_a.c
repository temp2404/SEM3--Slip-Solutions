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

void insert_last()
{
    NODE *temp, *new_node;
    temp = head;
    new_node = (NODE *)malloc(sizeof(NODE));
    printf("Enter New node Data: ");
    scanf("%d", &new_node->data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}

void delete()
{
    NODE *temp, *prev, *t;
    int i, count = 0, pos;
    temp = head;
    printf("Enter Position to Delete: ");
    scanf("%d", &pos);
    for (t = head; t != NULL; t = t->next)
        count++;
    if (pos > count)
        printf("Invalid Position");
    else if (pos == 1)
    {
        head = head->next;
        free(temp);
    }
    else
    {
        for (i = 1, prev = head, t = head; i <= pos - 1; i++)
        {
            prev = t;
            t = t->next;
        }
        prev->next = t->next;
        free(t);
    }
}

int main()
{
    int opt;
    do
    {
        printf("\n\nMenu:\n1 : Create\n2 : Display\n3 : Insert At Last\n4 : Delete\n5 : Exit");
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
            insert_last();
            break;
        case 4:
            delete ();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Invalid Option");
        }
    } while (opt != 5);

    return 0;
}