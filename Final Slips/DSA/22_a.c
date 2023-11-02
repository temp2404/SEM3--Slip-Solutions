#include <stdio.h>
#include <string.h>

#define MAX 10

char data[MAX];
int top;

void init()
{
    top = -1;
}

int isFull()
{
    return top == MAX - 1;
}

int isEmpty()
{
    return top == -1;
}

char pop()
{
    if (isEmpty())
        printf("\nStack Underflow");
    else
        return data[top--];
}

void push(char ch)
{
    if (isFull())
        printf("\nStack Overflow");
    else
        data[++top] = ch;
}

void checkParenthesis()
{
    while (!isEmpty())
    {
        if (pop() == '(')
        {
            printf("\nGiven Expression is Parenthesized");
            break;
        }
    }
    if (isEmpty())
        printf("\nGiven Expreesion is not Parenthesized");
}

int main()
{
    char exp[MAX];
    printf("Enter Expression: ");
    gets(exp);
    init();
    for (int i = 0; i < strlen(exp); i++)
        push(exp[i]);
    checkParenthesis();

    return 0;
}