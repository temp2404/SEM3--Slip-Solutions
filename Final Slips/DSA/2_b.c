#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} NODE;

NODE *head = NULL;

void create_node()
{
    int i, n;
    NODE *temp, *current_node;
    printf("Give number of nodes: ");
    scanf("%d", &n);
    head = (NODE *)malloc(sizeof(NODE));
    printf("Enter Node 1: ");
    scanf("%d", &head->data);
    temp = head;
    temp->prev = NULL;
    temp->next = NULL;
    current_node = head;
    for (i = 2; i <= n; i++)
    {
        current_node->next = (NODE *)malloc(sizeof(NODE));
        temp = current_node;
        current_node = current_node->next;
        printf("Enter Node %d: ", i);
        scanf("%d", &current_node->data);
        current_node->prev = temp;
    }
    current_node->next = head;
}

void display_list()
{
    NODE *temp;
    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    create_node();
    display_list();
    return 0;
}