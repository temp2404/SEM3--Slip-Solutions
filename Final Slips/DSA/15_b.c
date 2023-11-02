#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} STACK;

STACK *head = NULL;

int isEmpty()
{
    return head == NULL;
}

void push(int value)
{
    STACK *newNode = (STACK *)malloc(sizeof(STACK));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

int pop()
{
    STACK *temp = head;
    if (isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int poppedElement = head->data;
        head = head->next;
        free(temp);
        return poppedElement;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack Elements: ");
    STACK *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch, n;
    do
    {
        printf("\nMenu\n1: Push\n2: Pop\n3: Display\n4: Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to be pushed into Stack: ");
            scanf("%d", &n);
            push(n);
            display();
            break;
        case 2:
            printf("Popped Element: %d\n", pop());
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 4);

    return 0;
}
