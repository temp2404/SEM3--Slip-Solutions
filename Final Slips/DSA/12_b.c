#include <stdio.h>

void selection_sort(int *a, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min_idx] > a[j])
            {
                min_idx = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[10], n, i, j;
    printf("Give size of List: ");
    scanf("%d", &n);
    printf("Enter a elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nOriginal List: ");
    print_array(a, n);

    selection_sort(a, n);
    printf("\nSorted List: ");
    print_array(a, n);

    return 0;
}