#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char data;
    struct stack *next;
} STACK;

STACK *head1 = NULL;
STACK *head2 = NULL;

int isEmpty(STACK **head)
{
    return head == NULL;
}

void push(STACK **head, char element)
{
    STACK *newnode = (STACK *)malloc(sizeof(STACK));
    newnode->data = element;
    newnode->next = *head;
    *head = newnode;
}

char pop(STACK **head)
{
    STACK *temp = *head;
    if (isEmpty(head))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        STACK *t = *head;
        int poppedElement = t->data;
        t = t->next;
        free(temp);
        return poppedElement;
    }
}

void display(STACK **head)
{
    if (isEmpty(head))
    {
        printf("Stack is Empty\n");
        return;
    }
    // printf("Stack Elements: ");
    STACK *temp = *head;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse()
{
    while (head1 != NULL)
    {
        push(&head2, head1->data);
        head1 = head1->next;
    }
}

int main()
{
    char string[100];
    printf("Enter String: ");
    gets(string);
    strcpy(string, strrev(string));
    for (int i = 0; i < strlen(string); i++)
    {
        push(&head1, string[i]);
    }
    printf("Stack Elements: ");
    display(&head1);
    reverse();
    printf("\nRevserse : ");
    display(&head2);

    return 0;
}