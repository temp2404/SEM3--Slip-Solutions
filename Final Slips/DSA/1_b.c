#include <stdio.h>
#include <math.h>

int eval_poly(int a[], int n, int x)
{
    int i, sum = 0;
    for (i = n; i >= 0; i--)
    {
        int power = pow(x, i);
        sum = sum + a[i] * power;
    }

    return sum;
}

int main()
{
    int order, i, x, c1[10], sum;
    printf("Give order of First polynominal: ");
    scanf("%d", &order);
    printf("Enter Coefficients: ");
    for (i = order; i >= 0; i--)
        scanf("%d", &c1[i]);

    printf("\nFirst Polynomial : ");
    for (i = order; i >= 0; i--)
    {
        if (i == 0)
            printf("%d", c1[i]);
        else if (i == 1)
            printf("%dx+", c1[i]);
        else
            printf("%dx^%d+", c1[i], i);
    }

    printf("\nGive Value of X: ");
    scanf("%d", &x);

    sum = eval_poly(c1, order, x);
    printf("\nEvaluation of Given Polynomials : %d", sum);

    return 0;
}