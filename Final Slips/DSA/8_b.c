#include <stdio.h>

void insertion_sort(int *a, int n)
{
    int i, j, key;
    for (i = 1; i <= n - 1; i++)
    {
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[10], i, n;
    printf("Give size of array: ");
    scanf("%d", &n);
    printf("Enter Array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &a[i]);
    }
    printf("\nOriginal Array: ");
    print_array(a, n);

    insertion_sort(a, n);
    printf("\nSort Array: ");
    print_array(a, n);
    return 0;
}