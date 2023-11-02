#include <stdio.h>
#include <stdlib.h>

void merge_sort(int a[], int lb, int ub, int mid)
{
    int i, j, k;
    int n1 = mid - lb + 1, n2 = ub - mid;

    int *Lar = (int *)malloc(n1 * sizeof(int));
    int *Rar = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
    {
        Lar[i] = a[lb + i];
    }
    for (j = 0; j < n2; j++)
    {
        Rar[j] = a[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = lb;

    while (i < n1 && j < n2)
    {
        if (Lar[i] <= Rar[j])
        {
            a[k] = Lar[i];
            i++;
        }
        else
        {
            a[k] = Rar[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = Lar[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = Rar[j];
        j++;
        k++;
    }

    free(Lar);
    free(Rar);
}

void merge(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        merge(a, lb, mid);
        merge(a, mid + 1, ub);
        merge_sort(a, lb, ub, mid);
    }
}

int main()
{
    int a[25], i, n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nOriginal Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    merge(a, 0, n - 1);
    printf("\nSorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
