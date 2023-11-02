#include <stdio.h>

void input_poly(int c[], int d);
void display_poly(int c[], int d);
void add_poly(int a[], int b[], int d);

int main()
{
    int d, c1[10], c2[10], i;
    printf("Enter No of Degree: ");
    scanf("%d", &d);

    printf("Enter Coefficients of Polynomial 1: ");
    input_poly(c1, d);

    printf("Enter Coefficients of Polynomial 2: ");
    input_poly(c2, d);

    printf("First Polynomial: ");
    display_poly(c1, d);

    printf("Second Polynomial: ");
    display_poly(c2, d);

    printf("Addition of Both Polynomials: ");
    add_poly(c1, c2, d);

    return 0;
}

void input_poly(int c[], int d)
{
    for (int i = d; i >= 0; i--)
        scanf("%d", &c[i]);
    printf("\n");
}

void display_poly(int c[], int d)
{
    for (int i = d; i >= 0; i--)
    {
        if (i == 0)
            printf("%d", c[i]);
        else if (i == 1)
            printf("%dx+", c[i]);
        else
            printf("%dx^%d+", c[i], i);
    }
    printf("\n");
}

void add_poly(int a[], int b[], int d)
{
    for (int i = d; i >= 0; i--)
    {
        if (i == 0)
            printf("%d", a[i] + b[i]);
        else if (i == 1)
            printf("%dx+", a[i] + b[i]);
        else
            printf("%dx^%d+", a[i] + b[i], i);
    }
    printf("\n");
}
