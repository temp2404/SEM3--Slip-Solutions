#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

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

void eval(char *exp)
{
    int result = 0, m, n;
    init();
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(exp[i] - 48);
        }
        else
        {
            switch (exp[i])
            {
            case '^':
            case '$':
                m = pop();
                n = pop();
                push(n ^ m);
                break;
            case '*':
                m = pop();
                n = pop();
                push(n * m);
                break;
            case '/':
                m = pop();
                n = pop();
                push(n / m);
                break;
            case '+':
                m = pop();
                n = pop();
                push(n + m);
                break;
            case '-':
                m = pop();
                n = pop();
                push(n - m);
                break;
            default:
                printf("Invalid operator");
            }
        }
    }
    printf("Evaluation of %s : %d", exp, pop());
}

int main()
{
    char expression[MAX];
    printf("Enter Postfix Expression: ");
    gets(expression);
    eval(expression);

    return 0;
}