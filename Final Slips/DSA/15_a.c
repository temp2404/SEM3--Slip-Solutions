#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

struct Node *head = NULL;

void push(char data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

char pop()
{
    if (head == NULL)
    {
        printf("Stack is empty!\n");
        return '\0';
    }

    char data = head->data;
    head = head->next;
    free(head);

    return data;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '^':
    case '$':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void convertInfixToPostfix(char *infix, char *postfix)
{
    int i, j;
    i = j = 0;
    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (isOperand(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (head->data != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (head != NULL && precedence(ch) <= precedence(head->data))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    while (head != NULL)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    convertInfixToPostfix(infix, postfix);

    printf("The equivalent postfix expression is: %s\n", postfix);

    return 0;
}
