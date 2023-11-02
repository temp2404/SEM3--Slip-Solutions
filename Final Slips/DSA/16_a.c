#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct stack
{
    char data[MAX];
    int top;
} STACK;

STACK s1;

void init()
{
    s1.top = -1;
}

int isEmpty()
{
    if (s1.top == -1)
        return 1;
    return 0;
}

int isFull()
{
    if (s1.top == MAX - 1)
        return 1;
    return 0;
}

void push(char data)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    s1.data[++(s1.top)] = data;
}

char pop()
{
    return s1.data[s1.top--];
}

void display()
{
    for (int i = 0; i <= s1.top; i++)
    {
        printf("%s", s1.data[i]);
    }
    printf("\n");
}

void reverseWords(char *str)
{
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            while (!isEmpty())
                str[j++] = pop();
        }
        else
            push(str[i]);
    }
    while (!isEmpty())
        str[j++] = pop();

    str[j] = '\0';
    printf("Reverse of Given string: %s\n", str);
}
/*
This is a string
sihT_is_a_string
sihT_si_a_string
sihT_si_a_string
sihT_si_a_gnirts
*/
int main()
{
    int i;
    char str[MAX], temp[MAX];
    init(&s1);
    printf("Enter string: ");
    gets(str);
    reverseWords(str);
    return 0;
}
