#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct stack
{
    char data[MAX];
    int top;
} STACK;

STACK s;

void init()
{
    s.top = -1;
}

int isEmpty()
{
    if (s.top == -1)
        return 1;
    return 0;
}

int isFull()
{
    if (s.top == MAX - 1)
        return 1;
    return 0;
}

void push(char data)
{
    if (isFull(s))
    {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    s.data[++(s.top)] = data;
}

char pop()
{
    return s.data[s.top--];
}

void display()
{
    for (int i = 0; i <= s.top; i++)
    {
        printf("%c", s.data[i]);
    }
    printf("\n");
}

int main()
{
    char string[MAX];
    init();
    printf("Enter String: ");
    gets(string);
    for (int i = 0; i < strlen(string); i++)
        push(string[i]);

    printf("Stack : ");
    display();

    printf("Reverse String: ");
    while (s.top != -1)
        printf("%c", s.data[s.top--]);

    return 0;
}
